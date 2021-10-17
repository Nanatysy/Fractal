//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"

void	set_init(t_all *all, char **argv)
{
	if (ft_strncmp(argv[1], "Julia set", ft_strlen("Julia set") + 1) == 0)
		all->img_data->set = JULIA;
	else if (ft_strncmp(argv[1], "Mandelbrot set",
			ft_strlen("Mandelbrot set") + 1) == 0)
		all->img_data->set = MANDELBROT;
	else
		all->img_data->set = W_SET;
	all->img_data->f_bel[0] = &check_belongings_j;
	all->img_data->f_bel[1] = &check_belongings_m;
}

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc != 2 && argc != 4)
		return (print_errors(ARG_NUM_ERROR));
	if (argc == 4)
	{
		all.cx = ft_atof(argv[2]);
		all.cy = ft_atof(argv[3]);
	}
	init_struct(&all);
	set_init(&all, argv);
	if (all.img_data->set == W_SET)
		free_and_exit(&all, WRONG_SET);
	if (all.img_data->set == JULIA && argc != 4)
		free_and_exit(&all, ARG_NUM_ERROR_J);
	mlx_start(&all);
	return (0);
}
