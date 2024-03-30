
set(TARGET_NAME MGameRuntime)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Add source files ----
file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp")

#source_group(TREE "${ENGINE_ROOT_DIR}/schema" FILES ${SCHEMA_FILES})
source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${HEADER_FILES} ${SOURCE_FILES})


add_library(${TARGET_NAME} ${HEADER_FILES} ${SOURCE_FILES})

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 17)
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "Engine")

# being a cross-platform target, we enforce standards conformance on MSVC
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/permissive->")
target_compile_options(${TARGET_NAME} PUBLIC "$<$<COMPILE_LANG_AND_ID:CXX,MSVC>:/WX->")

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)

target_include_directories(
  ${TARGET_NAME} 
  PUBLIC $<BUILD_INTERFACE:${ENGINE_ROOT_DIR}/source/runtime>
  $<INSTALL_INTERFACE:include/${TARGET_NAME}-${PROJECT_VERSION}>
)



# ---- Create an installable target ----
# this allows users to install and find the library via `find_package()`.

# the location where the project's version header will be placed should match the project's regular
# header paths
string(TOLOWER ${TARGET_NAME}/version.h VERSION_HEADER_LOCATION)

### precompile
# set global vari used by precompile
set(MGAME_RUNTIME_HEADS "${HEADER_FILES}" PARENT_SCOPE)