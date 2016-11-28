cmake_minimum_required (VERSION 2.6)
project (benchmark_example)
set(CMAKE_CXX_FLAGS "-std=c++11")

set( GBENCH_SOURCE_DIR CACHE PATH "GoogleBenchmark top directory" )
set( GBENCH_BUILD_DIR  CACHE PATH "GoogleBenchmark build directory" )

# GBENCH config
get_filename_component( GBENCH_INCLUDE_DIR "${GBENCH_SOURCE_DIR}/include" REALPATH )
get_filename_component( GBENCH_LIBRARY "${GBENCH_BUILD_DIR}/src/libbenchmark.a" REALPATH )

# Validate directories
if( NOT EXISTS "${GBENCH_INCLUDE_DIR}/" )
    message( SEND_ERROR "GoogleBenchmark include directories missing. \nEnsure GBENCH_SOURCE_DIR is correctly set to GoogleBenchmark top directory." )
endif()

if( NOT EXISTS "${GBENCH_LIBRARY}" )
    message( SEND_ERROR "GoogleBenchmark library not found. \nEnsure GBENCH_BUILD_DIR is correctly set to GoogleBenchmark build directory." )
endif()

# Set include directories
include_directories(${GBENCH_INCLUDE_DIR})

set(BENCH_FILES_SRC example1.cpp)

add_executable(benchmark_example ${BENCH_FILES_SRC})

target_link_libraries(benchmark_example LINK_PUBLIC ${GBENCH_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})


