cmake_minimum_required(VERSION 3.5)
project(06_Top_K_Frequent_Elements)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(06_Top_K_Frequent_Elements ${SOURCE_FILES})