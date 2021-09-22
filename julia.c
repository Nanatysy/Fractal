//
// Created by Debby Willette on 9/21/21.
//

#include "fractol.h"

int	check_belongings_j(double x, double y)
{
	int		i;
	double	xn;
	double	yn;
	double tmp;
//	double	cx = 0.14096943887775515;
//	double	cy = 0.5995240480961923;
//	double	cx = -0.8021167334669339;
//	double	cy = 0.2497745490981964;


//	double	cx = 0.355;
//	double	cy = 0.355;
	double	cx = -0.4;
	double	cy = -0.59;
//	double	cx = -0.75;
//	double	cy = 0.2;


	i = 0;
	xn = x;
	yn = y;

	while (i < 100)
	{
		tmp = xn * xn - yn * yn + cx;
		yn = 2 * xn * yn + cy;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	return (100);
}

int	find_color(int iter)
{
	return (16772215 - iter * 167772);
}

void show_color_map(t_img_data *data)
{
	int x;
	int y;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, find_color(x * 100 / WIN_WIDTH));
			y++;
		}
		x++;
	}
}


void	render_image_j(t_img_data *data)
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
			z = check_belongings_j(x_tmp, y_tmp);
//			if (z == 100)
//				my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
//			else if (z > 70)
//				my_mlx_pixel_put(data, x, y, 0x00FFEFD5);
//			else if (z > 45)
//				my_mlx_pixel_put(data, x, y, 0x00FFA07A);
//			else if (z > 10)
//				my_mlx_pixel_put(data, x, y, 0x00A52A2A);
//			else
//				my_mlx_pixel_put(data, x, y, 0x00800000);
			my_mlx_pixel_put(data, x, y, find_color(z));
			x_tmp += x_step;
			x++;
		}
		y_tmp -= y_step;
		y++;
	}


//	show_color_map(data);
}