cmake_minimum_required(VERSION 3.5)
project(01_Fibonacci)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main2.cpp)
add_executable(01_Fibonacci ${SOURCE_FILES})