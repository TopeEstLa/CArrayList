cmake_minimum_required(VERSION 3.27)
project(CArrayList C)

set(CMAKE_C_STANDARD 11)

add_library(CArrayList STATIC array_list.c)
