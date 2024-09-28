cmake_minimum_required(VERSION 3.5)
project(raylib-rpg)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

set(HEADER_DIRS
    .
    core
    game
)

add_executable(${PROJECT_NAME} main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)
target_precompile_headers(${PROJECT_NAME} PRIVATE core/etc/system_includes.h)

# Core source files
aux_source_directory(core/app SOURCE_FILES)
aux_source_directory(core/scene SOURCE_FILES)
aux_source_directory(core/time SOURCE_FILES)
aux_source_directory(core/renderer SOURCE_FILES)
aux_source_directory(core/entity SOURCE_FILES)
aux_source_directory(core/serialization SOURCE_FILES)
aux_source_directory(core/gui/buttons SOURCE_FILES)
aux_source_directory(core/gui/textbox SOURCE_FILES)
aux_source_directory(core/gui/text SOURCE_FILES)
aux_source_directory(core/gui/images SOURCE_FILES)

# Game source files
aux_source_directory(game/scenes SOURCE_FILES)
aux_source_directory(game/managers SOURCE_FILES)
aux_source_directory(game/entity SOURCE_FILES)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_DIRS})

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/.install)

install(
    TARGETS raylib-rpg
    PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                GROUP_READ GROUP_EXECUTE
                WORLD_READ WORLD_EXECUTE
)

install(
    DIRECTORY game/resources
    DESTINATION .
)