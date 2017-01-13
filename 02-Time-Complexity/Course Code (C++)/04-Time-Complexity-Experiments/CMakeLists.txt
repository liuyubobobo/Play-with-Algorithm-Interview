cmake_minimum_required(VERSION 3.5)
project(03_Time_Complexity_Experiments)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main4.cpp MyUtil.h MyAlgorithmTester.h)
add_executable(03_Time_Complexity_Experiments ${SOURCE_FILES})