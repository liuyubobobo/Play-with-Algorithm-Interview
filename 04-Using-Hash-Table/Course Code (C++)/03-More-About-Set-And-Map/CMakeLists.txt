cmake_minimum_required(VERSION 3.5)
project(02_More_About_Set_And_Map)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main2.cpp)
add_executable(02_More_About_Set_And_Map ${SOURCE_FILES})