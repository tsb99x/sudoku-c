# Internal Libraries

add_library(context
        context.c
        context.h)
target_link_libraries(context
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf)

add_library(layout
        layout.c
        layout.h)
target_link_libraries(layout
        SDL3::SDL3)

add_library(grid
        grid.c
        grid.h)

add_library(button
        button.c
        button.h)
target_link_libraries(button
        context
        grid)

add_library(palette
        palette.c
        palette.h)
target_link_libraries(palette
        SDL3::SDL3)

add_library(digit
        digit.c
        digit.h)
target_link_libraries(digit
        context
        palette)

add_library(game_scene
        game_scene.c
        game_scene.h)
target_link_libraries(game_scene
        button
        context
        digit
        grid
        layout
        SDL3::SDL3
        palette)

# Application

if (MSVC)
        add_compile_definitions(SUDOKU_FONT="C:/Windows/Fonts/Arial.ttf")
else()
        add_compile_definitions(SUDOKU_FONT="/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")
endif()

set(EXT_LIBS
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf)
set(INT_LIBS
        context
        game_scene)
add_executable(${PROJECT_NAME} WIN32
        main.c)
target_link_libraries(${PROJECT_NAME}
        ${EXT_LIBS}
        ${INT_LIBS})
