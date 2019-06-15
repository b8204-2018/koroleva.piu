cmake_minimum_required(VERSION 3.12)
project(rpn)

set(CMAKE_CXX_STANDARD 14)

add_executable(rpn main.cpp rpn_lib.cpp rpn_lib.h )
add_executable(test test_main.cpp test.cpp rpn_lib.cpp rpn_lib.h)