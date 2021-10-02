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
		return (MAX_ITERATIONS);
	while (i < MAX_ITERATIONS)
	{
		tmp = xn * xn - yn * yn + x;
		yn = 2 * xn * yn + y;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	return (i);
}

void	render_image_m(t_img_data *data)
{
	t_mlx_coord	c;

	c.x_step = data->info->cur_width / (double)WIN_WIDTH;
	c.y_step = data->info->cur_height / (double)WIN_HEIGHT;
	c.y = 0;
	c.y_tmp = data->info->y_corner;
	while (c.y < WIN_HEIGHT)
	{
		c.x = 0;
		c.x_tmp = data->info->x_corner;
		while (c.x < WIN_WIDTH)
		{
			c.res = check_belongings_m(c.x_tmp, c.y_tmp);
			my_mlx_pixel_put(data, c.x, c.y, data->f[data->index](c.res,
					data->pow_4, data->pow_2));
			c.x_tmp += c.x_step;
			c.x++;
		}
		c.y_tmp -= c.y_step;
		c.y++;
	}
}
