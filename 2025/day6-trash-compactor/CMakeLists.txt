cmake_minimum_required(VERSION 4.0)
project(day6_trash_compactor)

set(CMAKE_CXX_STANDARD 20)

add_executable(day6_trash_compactor main.cpp
        CephalopodCalculator.cpp
        CephalopodCalculator.h)
