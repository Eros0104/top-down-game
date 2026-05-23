cmake_minimum_required(VERSION 3.21)
project(top-down-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# --- SDL2 ---
set(SDL_SHARED  ON  CACHE BOOL "" FORCE)
set(SDL_STATIC  OFF CACHE BOOL "" FORCE)
set(SDL_TEST    OFF CACHE BOOL "" FORCE)
FetchContent_Declare(SDL2
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.30.9/SDL2-2.30.9.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(SDL2)

# --- SDL2_image ---
# SDL2IMAGE_VENDORED bundles libpng/libjpeg so the build is fully self-contained.
# Set it to OFF if you'd rather use system image libs and speed up the first build.
set(SDL2IMAGE_INSTALL  OFF CACHE BOOL "" FORCE)
set(SDL2IMAGE_VENDORED ON  CACHE BOOL "" FORCE)
FetchContent_Declare(SDL2_image
    URL https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.2/SDL2_image-2.8.2.tar.gz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(SDL2_image)

# SDL2_image's source layout has SDL_image.h directly in include/, not inside an SDL2/
# subdirectory. Mirror SDL2's layout so #include "SDL2/SDL_image.h" resolves correctly.
FetchContent_GetProperties(SDL2_image)
configure_file(
    "${sdl2_image_SOURCE_DIR}/include/SDL_image.h"
    "${CMAKE_BINARY_DIR}/sdl2_image_compat/SDL2/SDL_image.h"
    COPYONLY
)

add_executable(game
    src/Main.cpp
    src/Game.cpp
    src/GameObject.cpp
    src/Map.cpp
    src/TextureManager.cpp
    src/Vector2D.cpp
    src/Collision.cpp
    src/EntityComponentSystem/EntityComponentSystem.cpp
)

target_include_directories(game PRIVATE "${CMAKE_BINARY_DIR}/sdl2_image_compat")

target_link_libraries(game PRIVATE
    SDL2::SDL2
    SDL2_image::SDL2_image
)
