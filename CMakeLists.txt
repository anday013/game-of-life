cmake_minimum_required(VERSION 3.10.2)
cmake_policy(SET CMP0076 NEW)
project(Game_Of_Life LANGUAGES C)

add_subdirectory(game)
add_subdirectory(console)
add_subdirectory(circular)
add_subdirectory(clipped)


add_executable(${PROJECT_NAME} main.c)


target_link_libraries(${PROJECT_NAME} PUBLIC game console circular clipped)
set(PROJECT_TEST test_gol)
add_executable(${PROJECT_TEST})
target_sources(${PROJECT_TEST} PUBLIC cunit.c)
target_link_libraries(${PROJECT_TEST} PUBLIC game cunit)

#CTest
enable_testing()
add_test(NAME "CunitTest" COMMAND ${PROJECT_TEST})

#Coverage
add_custom_target(cover
COMMAND cmake --build . --target test
COMMAND gcovr -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${PROJECT_TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(cover_html
COMMAND cmake --build . --target test
COMMAND gcovr --html --html-detail -o index.html -r ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR} $<TARGET_FILE:${PROJECT_TEST}>
WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

