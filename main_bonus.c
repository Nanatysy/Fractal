//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

void	set_init_bonus(t_all *all, char **argv)
{
	if (ft_strncmp(argv[1], "Julia set", ft_strlen("Julia set") + 1) == 0)
		all->img_data->set = JULIA;
	else if (ft_strncmp(argv[1], "Mandelbrot set",
						ft_strlen("Mandelbrot set") + 1) == 0)
		all->img_data->set = MANDELBROT;
	else if (ft_strncmp(argv[1], "Burning ship set",
						ft_strlen("Burning ship set") + 1) == 0)
		all->img_data->set = SHIP;
	else if (ft_strncmp(argv[1], "Dynamic Julia set",
						ft_strlen("Dynamic Julia set") + 1) == 0)
		all->img_data->set = DYNAMIC_J;
	else
		all->img_data->set = W_SET;
	all->img_data->f_bel[0] = &check_belongings_j;
	all->img_data->f_bel[1] = &check_belongings_m;
	all->img_data->f_bel[2] = &check_belongings_s;
}

int	main(int argc, char **argv) // TODO: mouse coord - c in julia
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
	set_init_bonus(&all, argv);
	if (all.set == W_SET)
		free_and_exit(&all, WRONG_SET);
	if (all.set == JULIA && argc != 4)
		free_and_exit(&all, ARG_NUM_ERROR_J);
	mlx_start_bonus(&all);
	return (0);
}
