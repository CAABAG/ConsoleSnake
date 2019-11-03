cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(ConsoleSnake)

add_executable(
ConsoleSnake
main.cpp
unitclass.cpp
playerclass.cpp
appleclass.cpp
pointsclass.cpp
constants.h
unitclass.h
playerclass.h
appleclass.h
pointsclass.h
)