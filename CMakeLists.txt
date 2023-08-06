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
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)

# Core source files
aux_source_directory(core/app SOURCE_FILES)
aux_source_directory(core/scene SOURCE_FILES)
aux_source_directory(core/time SOURCE_FILES)
aux_source_directory(core/renderer SOURCE_FILES)
aux_source_directory(core/entity SOURCE_FILES)
aux_source_directory(core/gui/buttons SOURCE_FILES)
aux_source_directory(core/gui/textbox SOURCE_FILES)
aux_source_directory(core/gui/text SOURCE_FILES)

# Game source files
aux_source_directory(game/scenes SOURCE_FILES)

target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_DIRS})

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")

    # Required linker flags for using Raylib with Emscripten
    target_link_options(${PROJECT_NAME} PRIVATE -sEXPORTED_FUNCTIONS=['_main','_malloc'] -sEXPORTED_RUNTIME_METHODS=ccall -sUSE_GLFW=3)
endif()