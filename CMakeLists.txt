cmake_minimum_required(VERSION 3.13)
project(Utils)

set(CMAKE_CXX_STANDARD 17)
add_compile_options(-Wall -O0)

add_library(Utils main.cpp defer.cpp defer.h)