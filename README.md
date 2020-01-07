# Benchmark Parallel
For test parallel implementations

# Require
C++ 17

## TBB
Install tbb and set enviroments variables, example for my build to Visual Studio 2019:
* **TBB_ROOT** ```C:\Libraries\tbb```
* **TBB_DIR** ```C:\Libraries\tbb\cmake```
* **TBB_INCLUDE_DIRS** ```C:\Libraries\tbb\include```
* **TBB_BIN_PATH** ```C:\Libraries\tbb\bin\intel64\vc142\```
* **TBB_LIBRARIES** ```C:\Libraries\tbb\lib\intel64\vc142```

```
git submodule update --init --recursive
```

## Google gtest and benchmark libraries
Build benchmark Release and Debug
```
cd benchmark
mkdir build
cd build
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release ..
```

# Build
```
mkdir build
cd build 
cmake -G "Visual Studio 16 2019" -DCMAKE_BUILD_TYPE=Release  ..
```

# Result
```
Run on (8 X 4008 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x4)
  L1 Instruction 32 KiB (x4)
  L2 Unified 256 KiB (x4)
  L3 Unified 8192 KiB (x1)
---------------------------------------------------------------------
Benchmark                           Time             CPU   Iterations
---------------------------------------------------------------------
BM_PPL/8/real_time            5692676 ns      4954268 ns          123
BM_PPL/64/real_time           5697408 ns      4662298 ns          124
BM_PPL/512/real_time          5633770 ns      4827236 ns          123
BM_PPL/4096/real_time         5650274 ns      4836310 ns          126
BM_PPL/8192/real_time         5681578 ns      4625000 ns          125
BM_Omp/8/real_time            4887061 ns      4357993 ns          147
BM_Omp/64/real_time           4861163 ns      4231771 ns          144
BM_Omp/512/real_time          4870495 ns      4202586 ns          145
BM_Omp/4096/real_time         4828306 ns      3521127 ns          142
BM_Omp/8192/real_time         4798615 ns      4370629 ns          143
BM_IntelTBB/8/real_time       3014235 ns      2933952 ns          229
BM_IntelTBB/64/real_time      3021075 ns      2938034 ns          234
BM_IntelTBB/512/real_time     3035308 ns      3017704 ns          233
BM_IntelTBB/4096/real_time    2976463 ns      3019958 ns          238
BM_IntelTBB/8192/real_time    2964752 ns      2925532 ns          235
Single/8/real_time           15912009 ns     15980114 ns           44
Single/64/real_time          15887070 ns     15980114 ns           44
Single/512/real_time         15891355 ns     15980114 ns           44
Single/4096/real_time        15886977 ns     15625000 ns           44
Single/8192/real_time        15949252 ns     15980114 ns           44

```
