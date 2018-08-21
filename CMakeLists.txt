cmake_minimum_required(VERSION 3.10)

add_library(rc STATIC src/rc.c src/rc.h)
target_compile_options(rc PRIVATE -Wall -Wconversion -Wextra)

enable_testing()

file(GLOB tests test/*.c)

foreach(filename ${tests})
  get_filename_component(target ${filename} NAME_WE)
  add_executable(${target} ${filename})
  target_link_libraries(${target} rc)
  add_test(${target} ${target})
endforeach()

install(TARGETS rc DESTINATION lib)
install(FILES src/rc.h DESTINATION include)
