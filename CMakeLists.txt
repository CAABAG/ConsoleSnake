cmake_minimum_required(VERSION "3.16.0")

project( "ConsoleSnake" )

set( SRC_LIST
"main.cpp"
"unitclass.cpp"
"playerclass.cpp"
"appleclass.cpp"
"pointsclass.cpp"
)

set( HDR_LIST
"constants.h"
"unitclass.h"
"playerclass.h"
"appleclass.h"
"pointsclass.h"
)

add_executable( "${PROJECT_NAME}" ${SRC_LIST} ${HDR_LIST} )
set_property(TARGET ConsoleSnake PROPERTY CXX_STANDARD 11)

#target_include_directories(ConsoleSnake PRIVATE ${PROJECT_BINARY_DIR})