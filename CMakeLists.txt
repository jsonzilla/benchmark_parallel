cmake_minimum_required(VERSION 2.8)
project(simple_benchmark_template CXX)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(GoogleBenchmark REQUIRED)

set(BENCHMARK_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/benchmark/include")
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    if ("${CMAKE_BUILD_TYPE}" MATCHES "Release")
        set(BENCHMARK_LIBRARIES "${CMAKE_SOURCE_DIR}/benchmark/build/src/Release/*.lib")
    else()
        set(BENCHMARK_LIBRARIES "${CMAKE_SOURCE_DIR}/benchmark/build/src/Debug/*.lib")
    endif()
endif()
include_directories(${BENCHMARK_INCLUDE_DIR})
include_directories(headers)

file(GLOB_RECURSE SOURCE_FILES headers/* src/*)

add_executable(simple_benchmark_template ${SOURCE_FILES})

target_link_libraries(simple_benchmark_template ${BENCHMARK_LIBRARIES})
if ("${CMAKE_SYSTEM_NAME}" MATCHES "Windows")
    target_link_libraries(simple_benchmark_template Shlwapi)
endif()
