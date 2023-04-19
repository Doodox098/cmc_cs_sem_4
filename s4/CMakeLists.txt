cmake_minimum_required(VERSION 3.24)
project(s4)

set(CMAKE_CXX_STANDARD 23)

add_executable(s4 complex.h complex_stack.h eval.h 03-4.cpp)
