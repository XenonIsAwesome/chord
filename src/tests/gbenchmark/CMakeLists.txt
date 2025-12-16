# =======================================================================================================
#  Set sources and parameters, add executable
# -------------------------------------------------------------------------------------------------------
file(GLOB_RECURSE BENCH_SOURCES CONFIGURE_DEPENDS *.cpp)
set(CMAKE_POSITION_INDEPENDENT_CODE OFF)

if (CHORD_BUILD_TOOLS)
    add_executable(bench_exec ${BENCH_SOURCES} )
endif()
# =======================================================================================================


# =======================================================================================================
#  Trial fetch and set GoogleBenchmark library from git
# -------------------------------------------------------------------------------------------------------
find_package(benchmark QUIET)

if(NOT benchmark_FOUND)
    message(STATUS "Fetching benchmark")

    include(FetchContent)
    set(BENCHMARK_USE_BUNDLED_GTEST OFF)
    FetchContent_Declare(
            benchmark
            GIT_REPOSITORY https://github.com/google/benchmark.git
            GIT_TAG v1.8.3
    )
    FetchContent_MakeAvailable(benchmark)
endif()

# turn off testing, not needed to test.
# Wants to include googletest for benchmark internal library tests which is not needed.
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "" FORCE)
set(BENCHMARK_ENABLE_GTEST_TESTS OFF CACHE BOOL "" FORCE)
# =======================================================================================================


# =======================================================================================================
#  Actually Fetch and link benchmark library to executable
# -------------------------------------------------------------------------------------------------------
target_link_libraries(bench_exec PUBLIC benchmark::benchmark impl_lib)
# =======================================================================================================

#target_sources(${PROJECT_NAME} PRIVATE ${BENCH_SOURCES})
