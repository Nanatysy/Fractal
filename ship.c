//
// Created by Debby Willette on 10/2/21.
//

#include "fractol.h"

int	my_expose(t_all *all)
{
	double	x_tmp;
	double	y_tmp;
	int		x;
	int		y;

	mlx_mouse_get_pos(all->mlx_win, &x, &y);
	x_tmp = all->img_data->info->x_corner + (x * \
			all->img_data->info->cur_width) / WIN_WIDTH;
	y_tmp = all->img_data->info->y_corner + (y * \
			all->img_data->info->cur_height) / WIN_HEIGHT;
	dynamic_julia(all, x_tmp, y_tmp);
	return (0);
}

int	dynamic_julia(t_all *all, double x, double y)
{
	all->cx = x;
	all->cy = y;
	render_image(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

int	check_belongings_s(double x, double y, double tmp1, double tmp2)
{
	int		i;
	double	xn;
	double	yn;
	double	tmp;

	i = 0;
	xn = x;
	yn = y;
	while (i < MAX_ITERATIONS)
	{
		tmp = xn * xn - yn * yn + x;
		yn = 2 * fabs(xn * yn) + y;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	(void)tmp1;
	(void)tmp2;
	return (i);
}
