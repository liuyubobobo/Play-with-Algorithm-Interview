cmake_minimum_required(VERSION 3.5)
project(05_0_1_backpack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main2.cpp)
add_executable(05_0_1_backpack ${SOURCE_FILES})