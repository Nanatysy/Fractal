//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

void	my_mlx_loop_bonus(t_all *all)
{
	printf("If you want to change fractol color, please press ENTER\n");
	mlx_hook(all->mlx_win, 2, 1L << 0, key_press, all);
	mlx_hook(all->mlx_win, 17, 1L << 16, my_close_x, all);
	if (all->img_data->set == DYNAMIC_J)
		mlx_loop_hook(all->mlx, my_expose, all);
	else
		mlx_mouse_hook(all->mlx_win, moise_catch_bonus, all);
	mlx_loop(all->mlx);
}

void	bonus_init(t_all *all)
{
	if (all->img_data->set == DYNAMIC_J)
	{
		all->cx = 0;
		all->cy = 0;
	}
	all->img_data->index_c = 0;
	all->img_data->f[0] = &find_color_rainbow;
	all->img_data->f[1] = &find_color_blue_and_yellow;
	all->img_data->f[2] = &find_color_pink_and_green;
}

void	mlx_start_bonus(t_all *all)
{
	int	screen_height;
	int	screen_width;

	all->mlx = mlx_init();
	bonus_init(all);
	mlx_get_screen_size(all->mlx, &screen_width, &screen_height);
	if (WIN_HEIGHT > screen_height || WIN_HEIGHT < 320 || WIN_WIDTH > \
			screen_width || WIN_WIDTH < 320)
		free_and_exit(all, SCREEN_SIZE);
	all->mlx_win = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	all->mlx_image = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img_data->addr = mlx_get_data_addr(all->mlx_image,
			&all->img_data->bits_per_pixel,
			&all->img_data->line_length,
			&all->img_data->endian);
	all->img_data->bytes_per_pixel = all->img_data->bits_per_pixel / 8;
	init_coord_structure(all->img_data->info, all->img_data->set);
	render_image(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	my_mlx_loop_bonus(all);
}
