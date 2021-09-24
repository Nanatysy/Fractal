//
// Created by Nastya on 19.09.2021.
//

#include "fractol.h"

int	moise_catch(int button, int x, int y, t_all *all)
{
	double	tmp;

	(void)x;
	(void)y;

	if (button == 5)
	{
		tmp = all->img_data->info->cur_height * 0.25;
		all->img_data->info->y_corner -= tmp / 2;
		all->img_data->info->cur_height -= tmp;
		tmp = all->img_data->info->cur_width * 0.25;
		all->img_data->info->x_corner += tmp / 2;
		all->img_data->info->cur_width -= tmp;
		if (all->set == MANDELBROT)
			render_image_m(all->img_data);
		else
			render_image_j(all->img_data, all->cx, all->cy);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}
	if (button == 4)
	{
		tmp = all->img_data->info->cur_height * 0.05;
		all->img_data->info->y_corner += tmp / 2;
		all->img_data->info->cur_height += tmp;
		tmp = all->img_data->info->cur_width * 0.05;
		all->img_data->info->x_corner -= tmp / 2;
		all->img_data->info->cur_width += tmp;
		if (all->set == MANDELBROT)
			render_image_m(all->img_data);
		else
			render_image_j(all->img_data, all->cx, all->cy);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}

	return (0);
}

void	mlx_start(t_all *all)
{
	int	screen_height;
	int	screen_width;

	all->mlx = mlx_init();

	mlx_get_screen_size(all->mlx, &screen_width, &screen_height);
	if (WIN_HEIGHT > screen_height || WIN_HEIGHT < 320 || WIN_WIDTH >
	        screen_width || WIN_WIDTH < 320)
		exit(777); // TODO: write good looking error message

	all->mlx_win = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	all->mlx_image = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img_data->addr = mlx_get_data_addr(all->mlx_image,
											&all->img_data->bits_per_pixel,
											&all->img_data->line_length,
											&all->img_data->endian);
	all->img_data->bytes_per_pixel = all->img_data->bits_per_pixel / 8;

	init_coord_structure(all->img_data->info, all->set);

	if (all->set == MANDELBROT)
		render_image_m(all->img_data);
	else
		render_image_j(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);

	mlx_hook(all->mlx_win, 2, 1L<<0, my_close, all);
	mlx_hook(all->mlx_win, 17, 1L<<16, my_close_x, all);
	mlx_mouse_hook(all->mlx_win, moise_catch, all);

	mlx_loop(all->mlx);
}
