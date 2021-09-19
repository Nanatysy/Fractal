cmake_minimum_required(VERSION 3.20)
project(Fract_ol C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

add_executable(fractol
        fractol.h
        errors.c
        main.c)

find_library(LIBFT ft libft)
find_library(MLX mlx minilibX)
target_link_libraries(fractol LINK_PUBLIC ${LIBFT})
target_link_libraries(fractol LINK_PUBLIC ${MLX})