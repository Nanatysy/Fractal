//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"
#include "./libft/libft.h"

int	main(int argc, char **argv)
{
	t_all all;
	if (argc < 2)
		return (print_errors(ARG_NUM_ERROR));

	if (ft_strncmp(argv[1], "Julia set", ft_strlen("Julia set") + 1) == 0)
		all.set = JULIA;
	else if (ft_strncmp(argv[1], "Mandelbrot set", ft_strlen("Mandelbrot set") + 1) == 0)
		all.set = MANDELBROT;
	else
		all.set = WRONG_SET;
	if (all.set == WRONG_SET)
		printf("Error, wrong set\n");

		return (0);
}