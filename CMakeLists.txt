cmake_minimum_required(VERSION "3.16.0")

project( ConsoleSnake  CXX )

set( SRC_LIST
main.cpp
unitclass.cpp
playerclass.cpp
appleclass.cpp
pointsclass.cpp
)

include_directories(
"${PROJECT_BINARY_DIR}"
)

add_executable( ConsoleSnake ${SRC_LIST} )
set_property(TARGET ConsoleSnake PROPERTY CXX_STANDARD 11)

target_include_directories(ConsoleSnake PUBLIC "${PROJECT_BINARY_DIR}")