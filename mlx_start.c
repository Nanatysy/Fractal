//
// Created by Nastya on 19.09.2021.
//

#include "fractol.h"

void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length + x * data->bytes_per_pixel);
	*(unsigned int *)pixel = color;
}

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

int	moise_catch(int button, int x, int y, t_all *all)
{
	// 5 zoom in
	// 4 zoom out
	// 1 left
	// 2 right
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
			render_image_j(all->img_data);
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
			render_image_j(all->img_data);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}

	return (0);
}

void	init_coord_structure(t_coord_info *data, int flag)
{
	if (flag == MANDELBROT)
	{
		data->x_corner = -2;
		data->y_corner = 1;
		data->cur_height = 2;
		data->cur_width = 3;
		data->x0 = -0.5;
		data->y0 = 0;
	}
	else
	{
		data->x_corner = -3;
		data->y_corner = 2;
		data->cur_height = 4;
		data->cur_width = 6;
		data->x0 = 0;
		data->y0 = 0;
	}
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
		render_image_j(all->img_data);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);

	mlx_hook(all->mlx_win, 2, 1L<<0, my_close, all);
	mlx_hook(all->mlx_win, 2, 1L<<0, key_press, all);
	mlx_hook(all->mlx_win, 17, 1L<<16, my_close_x, all);

	mlx_mouse_hook(all->mlx_win, moise_catch_bonus, all);

	mlx_loop(all->mlx);
}
