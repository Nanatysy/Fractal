//
// Created by Debby Willette on 9/21/21.
//

#include "fractol.h"

int	check_belong_to_cardioid(double x, double y)
{
	double	teta;
	double	quarter;
	double	half;

	quarter = 1. / 4;
	half = 1. / 2;
	teta = atan2(y, x - quarter);
	if (sqrt(pow((x - quarter), 2) + pow(y, 2)) <= half - half * cos(teta))
		return (1);
	return (0);
}

int	check_belongings_m(double x, double y)
{
	int		i;
	double	xn;
	double	yn;
	double	tmp;

	i = 0;
	xn = x;
	yn = y;

	if (check_belong_to_cardioid(x, y) == 1)
		return (1);

	while (i < 100)
	{
		tmp = xn * xn - yn * yn + x;
		yn = 2 * xn * yn + y;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (0);
		i++;
	}
	return (1);
}

void	render_image_m(t_img_data *data)
{
	double	x_step;
	double	y_step;
	double	x_tmp;
	double	y_tmp;
	int		x;
	int		y;

	x_step = (3 - (-2 - data->x_corner) * 2) / (double)WIN_WIDTH;
	y_step = (2 - (1 - data->y_corner) * 2) / (double)WIN_HEIGHT;
	y = 0;
	y_tmp = data->y_corner;

	while (y < WIN_HEIGHT)
	{
		x = 0;
		x_tmp = data->x_corner;
		while (x < WIN_WIDTH)
		{
			if (check_belongings_m(x_tmp, y_tmp) == 0)
				my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
			else
				my_mlx_pixel_put(data, x, y, 0x00000000);
			x_tmp += x_step;
			x++;
		}
		y_tmp -= y_step;
		y++;
	}
}