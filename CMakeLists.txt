cmake_minimum_required(VERSION 3.10)

add_library(rc STATIC src/rc.c)
target_compile_options(rc PRIVATE -Wall -Wconversion -Wextra)

install(TARGETS rc DESTINATION lib)
install(FILES src/rc.h DESTINATION include)
