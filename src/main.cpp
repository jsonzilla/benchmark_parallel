#include <benchmark\benchmark.h>

#include "tbb/blocked_range.h"
#include "tbb/parallel_for.h"

#include <omp.h>
#include <ppl.h> 

#include "diy.h"

// PREAMBULO
const int WORK = 2;
const int SIZE_OF_ARRAY = 1000;

__declspec(noinline)
void work(int index)
{
    int x = 0;
    for (int i = 0; i < WORK; i++)
    {
        x = i * (x + i);
    }
}

typedef void (*FNPTR) (int i);
FNPTR Func = work;

// CONCURRECY PPL
static void BM_MultiThreaded(benchmark::State& state) {
    if (state.thread_index == 0) {}
    for (auto _ : state) {        
        Concurrency::parallel_for(0, SIZE_OF_ARRAY, Func);
    }
    if (state.thread_index == 0) {}
}
BENCHMARK(BM_MultiThreaded)->Range(8, 8 << 10)->UseRealTime();

// OPENMP
static void BM_MultiThreadedOmp(benchmark::State& state) {
    if (state.thread_index == 0) {}
    for (auto _ : state) {
        #pragma omp parallel for
        for (int i = 0; i < SIZE_OF_ARRAY; i++) {
           Func(i);
        }
    }
    if (state.thread_index == 0) {}
}
BENCHMARK(BM_MultiThreadedOmp)->Range(8, 8 << 10)->UseRealTime();

// INTEL TBB
static void BM_MultiThreadedIntel(benchmark::State& state) {
    if (state.thread_index == 0) {}
    for (auto _ : state) {
        tbb::parallel_for(0, SIZE_OF_ARRAY, 1, Func, tbb::auto_partitioner());
    }
    if (state.thread_index == 0) {}
}

BENCHMARK(BM_MultiThreadedIntel)->Range(8, 8 << 10)->UseRealTime();

// Single
static void BM_MultiThreadedSingle(benchmark::State& state) {
    std::vector<int> v(SIZE_OF_ARRAY);
    std::generate(v.begin(), v.end(), DIY::f);
    if (state.thread_index == 0) {}
    for (auto _ : state) {
        std::for_each(v.begin(), v.end(), Func);
    }
    if (state.thread_index == 0) {}
}

BENCHMARK(BM_MultiThreadedSingle)->Range(8, 8 << 10)->UseRealTime();

//// DIY
//static void BM_MultiThreadedDIY(benchmark::State& state) {
//    std::vector<int> v(SIZE_OF_ARRAY);
//    std::generate(v.begin(), v.end(), DIY::f);
//    if (state.thread_index == 0) {}
//    for (auto _ : state) {
//        DIY::parallel_for_each(v.begin(), v.end(), Func);
//    }
//    if (state.thread_index == 0) {}
//}
//
//BENCHMARK(BM_MultiThreadedDIY)->Range(8, 8 << 10)->UseRealTime();

BENCHMARK_MAIN();