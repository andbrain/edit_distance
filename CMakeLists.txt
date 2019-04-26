cmake_minimum_required(VERSION 3.13)
project(edit_distance)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(edit_distance
        editDistance.h
        editDistanceClassical.cpp
        main.cpp
        README.md)
