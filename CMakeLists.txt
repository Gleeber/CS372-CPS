cmake_minimum_required(VERSION 3.13)
project(CS372_CPS)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS372_CPS shape.cpp shape.h cpsTest.cpp catch.hpp)