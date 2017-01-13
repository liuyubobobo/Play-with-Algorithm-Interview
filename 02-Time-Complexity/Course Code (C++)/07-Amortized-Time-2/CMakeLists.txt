cmake_minimum_required(VERSION 3.5)
project(06_Amortized_Time)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MyVector.h)
add_executable(06_Amortized_Time ${SOURCE_FILES})