cmake_minimum_required(VERSION 3.0)

project(clipped LANGUAGES C)


set(CMAKE_BUILD_TYPE Release)


add_library(clipped)
target_sources(clipped PRIVATE clipped.c clipped.h)
target_include_directories(clipped INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(clipped PUBLIC game)


target_compile_options(clipped PUBLIC "--coverage")
target_link_options(clipped PUBLIC "--coverage")