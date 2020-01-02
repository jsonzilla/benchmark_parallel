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


