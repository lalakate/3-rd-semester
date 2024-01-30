cmake_minimum_required(VERSION 3.26)
project(lab_4)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab_4 main.cpp
        calendar.cpp
        calendar.h
        source.cpp
        source.h)
