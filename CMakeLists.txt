cmake_minimum_required(VERSION 3.10)

add_library(rc STATIC rc.c)
target_compile_options(rc PRIVATE -Wall -Wextra)
