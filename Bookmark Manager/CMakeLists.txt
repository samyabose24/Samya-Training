cmake_minimum_required(VERSION 4.1)
project(Bookmark_Manager)

set(CMAKE_CXX_STANDARD 20)

add_executable(Bookmark_Manager main.cpp
        Bookmark.cpp
        Bookmark.h)
