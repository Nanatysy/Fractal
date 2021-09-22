cmake_minimum_required(VERSION 3.20)
project(Fract_ol C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(fractol
        fractol.h
        errors.c
        mandelbrot.c
        julia.c
        mlx_bonus.c
        main.c mlx_start.c)

find_library(LIBFT ft libft)
#find_library(MLX mlx minilibX)
file(GLOB LIBRARIES "${CMAKE_SOURCE_DIR}/libmlx.dylib")
target_link_libraries(fractol LINK_PUBLIC ${LIBFT})
target_link_libraries(fractol LINK_PUBLIC ${LIBRARIES})
target_link_options(fractol PUBLIC -framework OpenGL)
#target_link_options(fractol PUBLIC ${AppKit})