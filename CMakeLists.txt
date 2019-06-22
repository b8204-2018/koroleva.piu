cmake_minimum_required(VERSION 3.12)
project(shop)

set(CMAKE_CXX_STANDARD 14)

add_executable(shop main.cpp Shop.cpp Shop.h Customers.cpp Customers.h Money.cpp Money.h)