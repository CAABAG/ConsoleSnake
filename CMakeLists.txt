cmake_minimum_required(VERSION "3.16.0")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project("ConsoleSnake")

add_executable("${PROJECT_NAME}" "main.cpp" "constants.h" "unitclass.h" "unitclass.cpp" "playerclass.h" "playerclass.cpp" "appleclass.h" "appleclass.cpp" "pointsclass.h" "pointsclass.cpp")