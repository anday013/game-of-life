cmake_minimum_required(VERSION 3.0)

project(console LANGUAGES C)


set(CMAKE_BUILD_TYPE Release)


add_library(console)
target_sources(console PRIVATE ansi_console.c board_drawer.h)
target_include_directories(console INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(console PUBLIC game)


target_compile_options(console PUBLIC "--coverage")
target_link_options(console PUBLIC "--coverage")