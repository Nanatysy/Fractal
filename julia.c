//
// Created by Debby Willette on 9/21/21.
//

#include "fractol.h"

int	check_belongings_j(double x, double y, double cx, double cy)
{
	int		i;
	double	xn;
	double	yn;
	double tmp;

	i = 0;
	xn = x;
	yn = y;

	while (i < MAX_ITERATIONS)
	{
		tmp = xn * xn - yn * yn + cx;
		yn = 2 * xn * yn + cy;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	return (MAX_ITERATIONS);
}

int	find_color_blue_and_yellow(int iter)
{
	int	red = 0;
	int	green = 0;
	int	blue = 0;
	int	step;

	if (MAX_ITERATIONS % 4 != 0)
		step = (MAX_ITERATIONS + 4) / 4;
	else
		step = MAX_ITERATIONS / 4;

	iter = MAX_ITERATIONS - iter;

	if (iter < step)
	{
		red = iter * 255 / step;
		green = iter * 200 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 255;
		green = 200 + iter * 55 / step;
		blue = iter * 255 / step;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		red = 255 - iter * 255 / step;
		green = 255 - iter * 255 / step;
		blue = 255;
	}
	else
	{
		iter -= step * 3;
		blue = 255 - iter * 127 / step;
	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}

int	find_color_rainbow(int iter)
{
	int	red = 0;
	int	green = 0;
	int	blue = 0;
	int	step = MAX_ITERATIONS / 5;

	if (iter < step)
	{
		red = 255;
		green = iter * 255 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 255 - iter * 255 / step;
		green = 255;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		green = 255;
		blue = iter * 255 / step;
	}
	else if (iter < step * 4)
	{
		iter -= step * 3;
		green = 255 - iter * 255 / step;
		blue = 255;
	}
	else
	{
		iter -= step * 4;
		blue = 255 - iter * 255 / step;

	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}

void show_color_map(t_img_data *data)
{
	int x;
	int y;
	int	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		color = find_color_pink_and_green(x * MAX_ITERATIONS / WIN_WIDTH);
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}


void	render_image_j(t_img_data *data, double cx, double cy)
{
	double	x_step;
	double	y_step;
	double	x_tmp;
	double	y_tmp;
	int		x;
	int		y;
	int		z;

	x_step = data->info->cur_width / (double)WIN_WIDTH;
	y_step = data->info->cur_height / (double)WIN_HEIGHT;

	y = 0;
	y_tmp = data->info->y_corner;

	while (y < WIN_HEIGHT)
	{
		x = 0;

		x_tmp = data->info->x_corner;
		while (x < WIN_WIDTH)
		{
			z = check_belongings_j(x_tmp, y_tmp, cx, cy);
			my_mlx_pixel_put(data, x, y, data->f[data->index](z));
			x_tmp += x_step;
			x++;
		}
		y_tmp -= y_step;
		y++;
	}
//	(void)cx;
//	(void)cy;
//	show_color_map(data);
}