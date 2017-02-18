cmake_minimum_required(VERSION 3.5)
project(03_Non_Recursive_Implementation_of_a_Recursive_Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(03_Non_Recursive_Implementation_of_a_Recursive_Algorithm ${SOURCE_FILES})