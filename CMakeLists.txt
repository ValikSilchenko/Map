cmake_minimum_required(VERSION 3.21)
project(Map)

set(CMAKE_CXX_STANDARD 20)

add_executable(Map main.cpp Map.cpp Map.h Tree.cpp Tree.h)
