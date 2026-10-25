cmake_minimum_required(VERSION 3.16)
project(telesp CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)

add_executable(telesp
    src/main.cpp
    src/app.cpp
)
target_include_directories(telesp PRIVATE include ${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(telesp PRIVATE ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
