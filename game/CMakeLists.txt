cmake_minimum_required(VERSION 3.0)

project(game LANGUAGES C)
set(SOURCES game.c helper.c point.c)
set(HEADERS game.h helper.h point.h)


set(CMAKE_BUILD_TYPE Release)


add_library(game)
target_sources(game PRIVATE ${SOURCES} ${HEADERS})
target_include_directories(game INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries( game PUBLIC circular clipped)
