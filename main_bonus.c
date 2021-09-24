//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

int	main(int argc, char **argv) // TODO: add fractal set, add color changing
// option
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
		exit(9999); // TODO: change to error message
	all.img_data->info = malloc(sizeof(t_coord_info));
	if (!all.img_data->info)
		exit(8888);

	if (all.set == 0)
		return (print_errors(WRONG_SET));
	if (all.set == JULIA && argc != 4)
		exit(123); // TODO: change to proper error message and free memory
	mlx_start_bonus(&all);
	return (0);
}
