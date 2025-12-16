# =======================================================================================================
#  Pick files based on processor present
# -------------------------------------------------------------------------------------------------------
set(FILE_TYPES cpp tpp hpp inl)
set(INTEL_DIR ipp)
set(STD_DIR std)

# ARM support is currently implemented by using STD
if (ARM_PRESENT)
    set(OVERRIDE_USE_STD TRUE)
endif()

set(IMPL_DIR)
if (INTEL_PRESENT)
    set(IMPL_DIR ${INTEL_DIR})
elseif (OVERRIDE_USE_STD)
    set(IMPL_DIR ${STD_DIR})
endif ()

foreach (file_type ${FILE_TYPES})
    file(GLOB_RECURSE FILES_IN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${IMPL_DIR}/*.${file_type})

    list(APPEND IMPL_SOURCE_FILES ${FILES_IN_DIR})
endforeach ()

list(APPEND IMPL_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/lib_inst.cpp)
# =======================================================================================================


# =======================================================================================================
#  Create library, link include and other libraries
# -------------------------------------------------------------------------------------------------------
add_library(impl_lib STATIC ${IMPL_SOURCE_FILES})
set_target_properties(impl_lib PROPERTIES EXCLUDE_FROM_ALL TRUE)
# =======================================================================================================


# =======================================================================================================
#  Add compile definition according to processor chosen, link libs if needed
# -------------------------------------------------------------------------------------------------------

# Append needed module paths so that CMake discovers required libraries
#list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)
#if (EXISTS /opt/intel/ipp)
#    list(APPEND CMAKE_MODULE_PATH /opt/intel/ipp)
#endif ()

if (INTEL_PRESENT)
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13)
        target_compile_definitions(impl_lib PRIVATE _IPP_NO_FLOAT16)
    endif()

    list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

    if (EXISTS "/opt/intel/oneapi/ipp/latest/")
        set(IPP_ROOT "/opt/intel/oneapi/ipp/latest/")
        set(IPP_DIRECTORY "/opt/intel/oneapi/ipp/latest/")
        set(IPP_DIR "/opt/intel/oneapi/ipp/latest/")
    elseif (EXISTS "/opt/intel/ipp")
        set(IPP_DIRECTORY "/opt/intel/ipp/")
        set(IPP_DIR "/opt/intel/ipp/")
    endif ()
    list(APPEND CMAKE_MODULE_PATH ${IPP_DIRECTORY})

    set(IPP_LIBRARIES ${IPP_LIB_I} ${IPP_LIB_S} ${IPP_LIB_CORE})
    set(IPP_LIB_CH "")

    # We need IPP
    find_package(IPP REQUIRED)
    target_include_directories(impl_lib PUBLIC ${IPP_INCLUDE_DIRS})
    target_link_libraries(impl_lib PUBLIC ${IPP_LIBRARIES})


    target_compile_definitions(impl_lib PUBLIC INTEL_PRESENT=${INTEL_PRESENT})
elseif (OVERRIDE_USE_STD)
    target_compile_definitions(impl_lib PUBLIC OVERRIDE_USE_STD=${OVERRIDE_USE_STD})
endif ()
# =======================================================================================================

target_include_directories(impl_lib PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/include>
#        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/src/utils>
        PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        ${PROJECT_SOURCE_DIR}/src/impls
#        $<INSTALL_INTERFACE:include>
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
#        $<INSTALL_INTERFACE:include>
#        PRIVATE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/impls/${IMPL_DIR}>
#        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${IMPL_DIR}
)

message("gggggggggggggggggg" ${CMAKE_CURRENT_SOURCE_DIR})

#target_include_directories(impl_lib PRIVATE
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#)

#target_include_directories(impl_lib PUBLIC ${PROJECT_SOURCE_DIR}/include utils_lib)
#target_include_directories(impl_lib PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} utils_lib)


# =======================================================================================================
#  Include threads, for "init once" logic(uses mutex)
# -------------------------------------------------------------------------------------------------------
find_package(Threads REQUIRED)
target_link_libraries(impl_lib PUBLIC Threads::Threads utils_lib)
