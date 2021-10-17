cmake_minimum_required(VERSION 3.20)
project(Fract_ol C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(fractol
        fractol.h
        errors.c
        mandelbrot.c
        julia.c
        ft_atof.c
        mlx_start.c
        mlx_extra.c
        colors.c
        color_utils.c
        ship.c
        main.c)

add_executable(fractol_bonus
        fractol.h
        errors.c
        mandelbrot.c
        julia.c
        mlx_bonus.c
        ft_atof.c
        mlx_start_bonus.c
        mlx_extra.c
        main_bonus.c color_utils.c colors.c ship.c dynamic.c)

find_library(LIBFT ft libft)
file(GLOB LIBRARIES "${CMAKE_SOURCE_DIR}/libmlx.dylib")

target_link_libraries(fractol LINK_PUBLIC ${LIBFT})
target_link_libraries(fractol LINK_PUBLIC ${LIBRARIES})
target_link_options(fractol PUBLIC -framework OpenGL)
#target_link_options(fractol PUBLIC ${AppKit})

target_link_libraries(fractol_bonus LINK_PUBLIC ${LIBFT})
target_link_libraries(fractol_bonus LINK_PUBLIC ${LIBRARIES})
target_link_options(fractol_bonus PUBLIC -framework OpenGL)