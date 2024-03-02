
set(ENGINE_ROOT_DIR "${DXLEARN_ROOT_DIR}/engine")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")


if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DXLearnEditor)
endif()


add_subdirectory(source/runtime)
add_subdirectory(source/editor)
