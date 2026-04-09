cmake_minimum_required(VERSION 4.1)
project(Shapes_Manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(Shapes_Manager main.cpp
        Shape.cpp
        Shape.h
        Triangle.cpp
        Triangle.h
        Rectangle.cpp
        Rectangle.h
)
