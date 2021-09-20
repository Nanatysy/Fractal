//
// Created by Nastya on 19.09.2021.
//

#include "fractol.h"

int	my_close_x(t_all *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	exit(0);
}

int	my_close(int keycode, t_all *all)
{
	if (keycode == 53)
		my_close_x(all);
	return (1);
}

void	mlx_start(t_all *all)
{
	all->mlx = mlx_init();
	all->mlx_win = mlx_new_window(all->mlx, 800, 600, "fractol");
	mlx_hook(all->mlx_win, 2, 1L<<0, my_close, all);
	mlx_hook(all->mlx_win, 17, 1L<<16, my_close_x, all);
	mlx_loop(all->mlx);
}