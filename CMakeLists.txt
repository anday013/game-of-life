cmake_minimum_required(VERSION 3.10.2)
project(Game_Of_Life LANGUAGES C)

add_subdirectory(game)
add_subdirectory(circular)
add_subdirectory(clipped)


add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} PUBLIC game circular clipped)

