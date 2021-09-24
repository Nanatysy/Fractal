//
// Created by Debby Willette on 9/22/21.
//

#include "fractol.h"

int	find_color_pink_and_green(int iter)
{
	int	red = 0;
	int	green = 0;
	int	blue = 0;
	int	step;
//	iter = 250;
	if (MAX_ITERATIONS % 4 != 0)
		step = (MAX_ITERATIONS + 4) / 4;
	else
		step = MAX_ITERATIONS / 4;

	if (iter < step)
	{
		red = 220 + iter * 20 / step;
		green = 20 + iter * 108 / step;
		blue = 60 + iter * 68 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 240 + iter * 15 / step;
		green = 128 + iter * 127 / step;
		blue = 128 + iter * 127 / step;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		red = 255 - iter * 103 / step;
		green = 255 - iter * 4 / step;
		blue = 255 - iter * 103 / step;
	}
	else
	{
		iter -= step * 3;
		red = 152 - iter * 152 / step;
		green = 251 + iter * 4 / step;
		blue = 152 - iter * 25 / step;
	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}

int	key_press(int keycode, t_all *all)
{
	static	int tmp;

	if (keycode == 123)
		all->img_data->info->x_corner -= all->img_data->info->cur_width * 0.05
				/ 2;
	else if (keycode == 124)
		all->img_data->info->x_corner += all->img_data->info->cur_width * 0.05
										 / 2;
	else if (keycode == 125)
		all->img_data->info->y_corner -= all->img_data->info->cur_height * 0.05
										 / 2;
	else if (keycode == 126)
		all->img_data->info->y_corner += all->img_data->info->cur_height * 0.05
										 / 2;
	else if (keycode == 53)
		my_close_x(all);
	else if (keycode == 36)
		all->img_data->index = ++tmp % 3;

	if (all->set == MANDELBROT)
		render_image_m(all->img_data);
	else
		render_image_j(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

int	moise_catch_bonus(int button, int x, int y, t_all *all)
{
	double	tmp;
	double	x_tmp;
	double	y_tmp;

	mlx_mouse_get_pos(all->mlx_win, &x, &y);

	x_tmp = all->img_data->info->x_corner + (x *
			all->img_data->info->cur_width) / WIN_WIDTH;
	y_tmp = all->img_data->info->y_corner - (y *
			all->img_data->info->cur_height) / WIN_HEIGHT;

	all->img_data->info->x_corner += (x_tmp - all->img_data->info->x0) * 0.05;
	all->img_data->info->x0 += (x_tmp - all->img_data->info->x0) * 0.05;
	all->img_data->info->y_corner += (y_tmp - all->img_data->info->y0) * 0.05;
	all->img_data->info->y0 += (y_tmp - all->img_data->info->y0) * 0.05;

	if (button == 5)
	{
		tmp = all->img_data->info->cur_height * 0.05;
		all->img_data->info->y_corner -= tmp / 2;
		all->img_data->info->cur_height -= tmp;
		tmp = all->img_data->info->cur_width * 0.05;
		all->img_data->info->cur_width -= tmp;
		all->img_data->info->x_corner += tmp / 2;
		if (all->set == MANDELBROT)
			render_image_m(all->img_data);
		else
			render_image_j(all->img_data, all->cx, all->cy);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}
	if (button == 4) // просто уменьшать??? или оставиить
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

