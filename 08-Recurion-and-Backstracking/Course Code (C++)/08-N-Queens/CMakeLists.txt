cmake_minimum_required(VERSION 3.5)
project(08_N_Queens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(08_N_Queens ${SOURCE_FILES})