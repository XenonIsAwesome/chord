# =======================================================================================================
#  Set gtest source files and params
# -------------------------------------------------------------------------------------------------------
option(WITH_TEST_FAIL_LOGS "Output details of EACH element that caused the test to fail." ON)


file(GLOB_RECURSE IPP_TEST_SOURCES CONFIGURE_DEPENDS ipp_tests/*.test.cpp)
file(GLOB_RECURSE STD_TEST_SOURCES CONFIGURE_DEPENDS std_tests/*.cpp)
file(GLOB_RECURSE GTEST_SOURCES CONFIGURE_DEPENDS utils/*.cpp utils/*.hpp utils/*.tpp main.cpp std_tests/*.cpp library/*.cpp generic_tests/*.hpp)
# =======================================================================================================


# =======================================================================================================
# Based on processor present compile test folder
# -------------------------------------------------------------------------------------------------------
if (INTEL_PRESENT)
    if (CHORD_BUILD_TOOLS)
        add_executable(gtest_exec ${GTEST_SOURCES} ${IPP_TEST_SOURCES})
    endif()

    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13)
        target_compile_definitions(gtest_exec PRIVATE _IPP_NO_FLOAT16)
    endif()
    #    target_sources(${PROJECT_NAME} PRIVATE ${GTEST_SOURCES} ${IPP_TEST_SOURCES})
else()
    if (CHORD_BUILD_TOOLS)
        add_executable(gtest_exec ${GTEST_SOURCES} ${STD_TEST_SOURCES})
    endif()
    #    target_sources(${PROJECT_NAME} PRIVATE ${GTEST_SOURCES} ${STD_TEST_SOURCES})
endif ()

target_include_directories(gtest_exec PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/src/impls ${PROJECT_SOURCE_DIR}/src/utils)
target_link_libraries(gtest_exec PRIVATE utils_lib impl_lib GTest::gtest_main)

target_compile_definitions(gtest_exec PUBLIC WITH_TEST_FAIL_LOGS)
# =======================================================================================================

find_package(Python3 REQUIRED COMPONENTS Interpreter)


add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/library/smoke_tests_generated.test.cpp
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/utils/generate_smoke_tests.py
        --header ${CMAKE_SOURCE_DIR}/include/chord/lib.hpp
        --output ${CMAKE_CURRENT_SOURCE_DIR}/library/smoke_tests_generated.test.cpp
        DEPENDS ${CMAKE_SOURCE_DIR}/include/chord/lib.hpp
        COMMENT "Generating smoke tests"
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(generate_smoke_tests DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/library/smoke_tests_generated.test.cpp)

if (CHORD_BUILD_TOOLS)
    add_executable(smoke_tests ${CMAKE_CURRENT_SOURCE_DIR}/library/smoke_tests_generated.test.cpp)
endif()

add_dependencies(smoke_tests generate_smoke_tests)
target_include_directories(smoke_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(smoke_tests GTest::gtest_main pthread impl_lib)


# =======================================================================================================
#  Gtest find package and threads(needed for gtest)
# -------------------------------------------------------------------------------------------------------
find_package(Threads REQUIRED)

find_package(GTest)
if (NOT GTest_FOUND)
    message(STATUS "Fetching gtest")

    include(FetchContent)
    FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
endif ()

include(GoogleTest)

gtest_discover_tests(gtest_exec DISCOVERY_TIMEOUT 120)
# =======================================================================================================

