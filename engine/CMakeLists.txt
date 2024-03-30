
set(ENGINE_ROOT_DIR "${MGAME_ROOT_DIR}/engine")

set(DEPLOY_CONFIG_DIR "configs/deployment")
set(DEVELOP_CONFIG_DIR "configs/development")


if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options("/MP")
    set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT MGameEditor)
endif()


add_subdirectory(source/runtime)
add_subdirectory(source/editor)
add_subdirectory(source/meta_parser)

set(CODEGEN_TARGET "MGamePreCompile")
include(source/precompile/precompile.cmake)
set_target_properties("${CODEGEN_TARGET}" PROPERTIES FOLDER "Engine" )

add_dependencies(MGameRuntime "${CODEGEN_TARGET}")
add_dependencies("${CODEGEN_TARGET}" "MGameParser")
