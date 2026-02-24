cmake_minimum_required(VERSION 3.0)
project(SolarSystem)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/Cellar/sdl2_gfx/1.0.4/include)

link_directories(/usr/local/Cellar/sdl2_gfx/1.0.4/lib)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})



add_executable(SolarSystem main.c solar_system.c)
target_link_libraries(SolarSystem ${SDL2_LIBRARIES} SDL2_gfx)

