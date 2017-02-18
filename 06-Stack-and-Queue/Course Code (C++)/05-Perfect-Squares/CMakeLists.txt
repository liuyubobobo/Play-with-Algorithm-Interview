cmake_minimum_required(VERSION 3.5)
project(05_Perfect_Squares)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main3.cpp)
add_executable(05_Perfect_Squares ${SOURCE_FILES})