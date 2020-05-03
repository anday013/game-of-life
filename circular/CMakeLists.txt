cmake_minimum_required(VERSION 3.0)

project(circular LANGUAGES C)


set(CMAKE_BUILD_TYPE Release)


add_library(circular)
target_sources(circular PRIVATE circular.c circular.h)
target_include_directories(circular INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(circular PUBLIC game)


