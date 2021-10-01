//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

int	main(int argc, char **argv) // TODO: add fractal set
{
	t_all all;
	if (argc != 2 && argc != 4)
		return (print_errors(ARG_NUM_ERROR));

	if (argc == 4)
	{
		all.cx = ft_atof(argv[2]);
		all.cy = ft_atof(argv[3]);
	}

	if (ft_strncmp(argv[1], "Julia set", ft_strlen("Julia set") + 1) == 0)
		all.set = JULIA;
	else if (ft_strncmp(argv[1], "Mandelbrot set", ft_strlen("Mandelbrot set") + 1) == 0)
		all.set = MANDELBROT;
	else
		all.set = 0;

	all.img_data = malloc(sizeof(t_img_data));
	if (!all.img_data)
		free_and_exit(&all, MALLOC_ERROR);
	all.img_data->info = malloc(sizeof(t_coord_info));
	if (!all.img_data->info)
		free_and_exit(&all, MALLOC_ERROR);

	if (all.set == 0)
		free_and_exit(&all, WRONG_SET);
	if (all.set == JULIA && argc != 4)
		free_and_exit(&all, ARG_NUM_ERROR_J);
	mlx_start_bonus(&all);
	return (0);
}
