# =======================================================================================================
#  Set source files
# -------------------------------------------------------------------------------------------------------
set(FILE_TYPES cpp tpp hpp)
set(DIRS types builtin_math check_and_return_status random_generate)

foreach (dir ${DIRS})
    foreach (file_type ${FILE_TYPES})
        file(GLOB_RECURSE FILES_IN_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.${file_type})

        list(APPEND SOURCE_FILES ${FILES_IN_DIR})
    endforeach ()
endforeach ()
# =======================================================================================================

add_library(utils_lib STATIC ${SOURCE_FILES})

if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER_EQUAL 13)
    target_compile_definitions(utils_lib PRIVATE _IPP_NO_FLOAT16)
endif()

set_target_properties(utils_lib PROPERTIES LINKER_LANGUAGE CXX)


#target_include_directories(utils_lib PUBLIC
#        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
##        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
#        $<INSTALL_INTERFACE:include> $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src/utils
#)



target_include_directories(utils_lib PUBLIC
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
#        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
#        $<INSTALL_INTERFACE:include>
)

#target_link_libraries(utils_lib PRIVATE ${PROJECT_NAME})

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})
