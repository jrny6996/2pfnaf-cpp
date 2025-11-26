cmake_minimum_required(VERSION 3.0)
project(game CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# FetchContent: Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

# Collect project sources
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_LIST_DIR}/sources/*.cpp"
)

set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/sources/")

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})

# Link Raylib properly
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Asset path definition
target_compile_definitions(${PROJECT_NAME} PUBLIC
    ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/"
)

# Emscripten specific settings
if(EMSCRIPTEN)
    # Produce HTML + JS + WASM
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".html"
    )
    
    # Optional: enable filesystem support if you need to load assets dynamically
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS "--preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets@/assets"
    )
endif()
