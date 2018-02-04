cmake_minimum_required(VERSION 3.10)
project(conway_game_of_life)

set(CMAKE_CXX_STANDARD 11)

include_directories(include/)
file(GLOB srcs src/*.cpp)

add_executable(conway_game_of_life ${srcs})
add_executable(conway_game_of_life.exe ${srcs})
