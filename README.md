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
cmake -G "Visual Studio 16 2019" ..
```

# Build
```
mkdir build
cd build 
cmake -G "Visual Studio 16 2019" ..
```

# Result
```
Run on (12 X 2592 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 256 KiB (x6)
  L3 Unified 12288 KiB (x1)
--------------------------------------------------------------------------------
Benchmark                                      Time             CPU   Iterations
--------------------------------------------------------------------------------
BM_MultiThreaded/8/real_time                5480 ns         5325 ns       132040
BM_MultiThreaded/64/real_time               5356 ns         5107 ns       128512
BM_MultiThreaded/512/real_time              5264 ns         5172 ns       132917
BM_MultiThreaded/4096/real_time             5312 ns         5287 ns       130036
BM_MultiThreaded/8192/real_time             5261 ns         5191 ns       132447
BM_MultiThreadedOmp/8/real_time             1252 ns         1254 ns       560649
BM_MultiThreadedOmp/64/real_time            1231 ns         1231 ns       558508
BM_MultiThreadedOmp/512/real_time           1243 ns         1250 ns       562353
BM_MultiThreadedOmp/4096/real_time          1229 ns         1229 ns       559525
BM_MultiThreadedOmp/8192/real_time          1239 ns         1228 ns       560019
BM_MultiThreadedIntel/8/real_time           6841 ns         6817 ns       103149
BM_MultiThreadedIntel/64/real_time          6834 ns         6796 ns       101166
BM_MultiThreadedIntel/512/real_time         6828 ns         6788 ns        98974
BM_MultiThreadedIntel/4096/real_time        6851 ns         6848 ns       100392
BM_MultiThreadedIntel/8192/real_time        6828 ns         6857 ns       100266
BM_MultiThreadedSingle/8/real_time          1236 ns         1235 ns       569509
BM_MultiThreadedSingle/64/real_time         1247 ns         1223 ns       575025
BM_MultiThreadedSingle/512/real_time        1244 ns         1259 ns       570845
BM_MultiThreadedSingle/4096/real_time       1246 ns         1234 ns       569898
BM_MultiThreadedSingle/8192/real_time       1232 ns         1236 ns       568712

```
