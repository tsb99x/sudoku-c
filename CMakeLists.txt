cmake_minimum_required(VERSION 3.13)
project(sudoku LANGUAGES C)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

enable_testing()

add_subdirectory(vendored/SDL EXCLUDE_FROM_ALL)
add_subdirectory(vendored/SDL_ttf EXCLUDE_FROM_ALL)

if(MSVC)
        add_compile_options(/W4 /WX)
        add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
        add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

add_subdirectory(src)
