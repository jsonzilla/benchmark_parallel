cmake_minimum_required(VERSION 3.0)
project(simple_benchmark_template)
set(CMAKE_CXX_STANDARD 14)
set(OpenMP_CXX_FLAGS "-Xclang -openmp -Qpar")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

include_directories(simple_benchmark_template headers)

find_package(Threads REQUIRED)
find_package(GoogleBenchmark REQUIRED)

set(BENCHMARK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/benchmark/include")
include_directories(simple_benchmark_template ${BENCHMARK_INCLUDE_DIR})
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    if ("${CMAKE_BUILD_TYPE}" MATCHES "Release")
        set(BENCHMARK_LIBRARIES "${CMAKE_SOURCE_DIR}/benchmark/build/src/Release/*.lib")
    else()
        set(BENCHMARK_LIBRARIES "${CMAKE_SOURCE_DIR}/benchmark/build/src/Debug/*.lib")
    endif()
endif()

find_package(TBB REQUIRED)
include_directories(simple_benchmark_template $ENV{TBB_INCLUDE_DIRS})

file(GLOB_RECURSE SOURCE_FILES headers/* src/*)
add_executable(simple_benchmark_template ${SOURCE_FILES})

target_link_libraries(simple_benchmark_template ${BENCHMARK_LIBRARIES})
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    target_link_libraries(simple_benchmark_template Shlwapi)
endif()

target_link_libraries(simple_benchmark_template "$ENV{TBB_LIBRARIES}/*.lib")
