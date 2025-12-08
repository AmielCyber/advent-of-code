cmake_minimum_required(VERSION 4.0)
project(day2_gift_shop)

set(CMAKE_CXX_STANDARD 20)

add_executable(day2_gift_shop main.cpp
        InvalidIdCollector.cpp
        InvalidIdCollector.h)
