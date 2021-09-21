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
	double	cx = 0.14096943887775515;
	double	cy = 0.5995240480961923;
//	double	cx = -0.8021167334669339;
//	double	cy = 0.2497745490981964;

	i = 0;
	xn = x;
	yn = y;

	while (i < 50)
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

void	render_image_j(t_img_data *data)
{
	double	x_step;
	double	y_step;
	double	x_tmp;
	double	y_tmp;
	int		x;
	int		y;
	int		z;

	x_step = 4 / (double)WIN_WIDTH;
	y_step = 2 / (double)WIN_HEIGHT;
	y = 0;
	y_tmp = 1;

	while (y < WIN_HEIGHT)
	{
		x = 0;

		x_tmp = -2;
		while (x < WIN_WIDTH)
		{
			z = check_belongings_j(x_tmp, y_tmp);
			if (z == 100)
				my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
			else if (z > 70)
				my_mlx_pixel_put(data, x, y, 0x00FFEFD5);
			else if (z > 45)
				my_mlx_pixel_put(data, x, y, 0x00FFA07A);
			else if (z > 10)
				my_mlx_pixel_put(data, x, y, 0x00A52A2A);
			else
				my_mlx_pixel_put(data, x, y, 0x00800000);
			x_tmp += x_step;
			x++;
		}
		y_tmp -= y_step;
		y++;
	}
}