cmake_minimum_required(VERSION 3.18 FATAL_ERROR)
project(chord VERSION 1.0.0 LANGUAGES CXX)

if (NOT DEFINED PROJECT_IS_TOP_LEVEL)
    if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        set(PROJECT_IS_TOP_LEVEL TRUE)
    else()
        set(PROJECT_IS_TOP_LEVEL FALSE)
    endif()
endif()

option(CHORD_BUILD_TOOLS "Build Chord executables and tests and becnhmarks" ${PROJECT_IS_TOP_LEVEL})


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CHORD_VERSION 1.0)

# =======================================================================================================
#  Options
# -------------------------------------------------------------------------------------------------------
option(OVERRIDE_USE_STD "Override whatever processor is present(even if matches an option), and use implementation with std" OFF)
option(CHORD_ENABLE_TESTS "Enable building unit‑tests for library" OFF)
# =======================================================================================================


# =======================================================================================================
#  Processor definitions
# -------------------------------------------------------------------------------------------------------
set(INTEL_ARCHS "x86_64" "amd64")
set(ARM_ARCHS "arm" "armv7" "armv71" "aarch64" "arm64")
set(PRESENT_PROCESSOR ${CMAKE_SYSTEM_PROCESSOR})

message(STATUS "PROCESSOR ARCHITECTURE PRESENT = ${PRESENT_PROCESSOR}")

set(found_arch FALSE) # found what architecture the one present belongs to(i.e. intel)

set(INTEL_PRESENT FALSE)
set(ARM_PRESENT FALSE)
# =======================================================================================================


# =======================================================================================================
# Function to look for item in items list (if string items are equal)
# -------------------------------------------------------------------------------------------------------
function(item_in_list item list result)
    set(found FALSE)
    foreach (elem IN LISTS ${list})
        if (elem STREQUAL ${PRESENT_PROCESSOR})
            set(found TRUE)
            break()
        endif ()
    endforeach ()

    set(${result} ${found} PARENT_SCOPE) # set result in caller scope
endfunction()
# -------------------------------------------------------------------------------------------------------


# =======================================================================================================
# Check OVERRIDE_USE_STD and update if intel or arm
# -------------------------------------------------------------------------------------------------------
if (NOT OVERRIDE_USE_STD)
    item_in_list(item INTEL_ARCHS INTEL_PRESENT)  # check if intel
    if (NOT INTEL_PRESENT)  # if isn't intel try to look if arm
        item_in_list(item ARM_ARCHS ARM_PRESENT)  # check if arm
    endif ()

    if (INTEL_PRESENT OR ARM_PRESENT)
        set(found_arch TRUE)
    endif ()

    if (NOT found_arch)
        set(OVERRIDE_USE_STD TRUE)
    endif ()
endif ()

message(STATUS "ARM? ${ARM_PRESENT}")
message(STATUS "INTEL? ${INTEL_PRESENT}")
message(STATUS "STD? ${OVERRIDE_USE_STD}")
# =======================================================================================================


# =======================================================================================================
#  add option for of c++20 features(concepts)
# -------------------------------------------------------------------------------------------------------
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Werror>)
add_compile_options($<$<COMPILE_LANGUAGE:CXX>:-Wall>)  # enables all warning messages(i.e. unused variables)
add_compile_options($<$<AND:$<COMPILE_LANGUAGE:CXX>,$<CXX_COMPILER_ID:GNU>>:-fconcepts>) # enables the use of concepts in c++
# =======================================================================================================

# =======================================================================================================
#  Create chord library + installation
# -------------------------------------------------------------------------------------------------------
add_library(${PROJECT_NAME})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS chord)

add_subdirectory(src/utils)
add_subdirectory(src/impls)

# add tests
if (CHORD_ENABLE_TESTS)
    message(STATUS "Enabled Tests, Running")
    add_subdirectory(src/tests)
endif ()

set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

if (NOT CMAKE_BUILD_TYPE OR CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
    message(STATUS "Build type not specified: defaulting to release.")
endif ()


target_include_directories(
        ${PROJECT_NAME} INTERFACE
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

target_link_libraries(${PROJECT_NAME} INTERFACE impl_lib utils_lib)

target_link_libraries(${PROJECT_NAME} PUBLIC impl_lib PRIVATE utils_lib)
# TODO: Not expose impl_lib as public, but if else wise get undefined/no such file.
# Need to combine impl with chord library, not have a separate lib for.

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} EXPORT_NAME chord)  # SOVERSION?

# installation
install(DIRECTORY include/ DESTINATION include)

install(TARGETS ${PROJECT_NAME} impl_lib utils_lib
        EXPORT chordTargets
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
        INCLUDES DESTINATION include
)

install(
        EXPORT chordTargets
        NAMESPACE chord::
        DESTINATION lib/cmake/chord)


include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/chordConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)


configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/chordConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/chordConfig.cmake"
        INSTALL_DESTINATION "lib/cmake/chord")

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/chordConfig.cmake
        DESTINATION lib/cmake/chord)

# =======================================================================================================

# =======================================================================================================
#  Add executable for main
# -------------------------------------------------------------------------------------------------------
add_executable(main_exec main.cpp)
target_link_libraries(main_exec chord)
# =======================================================================================================
