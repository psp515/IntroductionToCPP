cmake_minimum_required(VERSION 3.24)
project(GameOfLive)

set(CMAKE_CXX_STANDARD 17)

add_executable(GameOfLive main.cpp live/Map.h live/Map.cpp)
