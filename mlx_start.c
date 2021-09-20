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

int	check_belongings(double x, double y)
{
	int		i;
	double	z;
	double	xn;
	double	yn;

	i = 0;
	z = 0;
	xn = x;
	yn = y;

	// TODO: optimisation
	if (check_belong_to_cardioid(x, y) == 1)
		return (1);

	while (i < 5000)
	{
		xn = pow(xn, 2) - pow(yn, 2) + x;
		yn = 2 * xn * yn + y;
		if (sqrt(pow(xn, 2) + pow(yn, 2)) > 2)
			return (0);
		i++;
	}
	return (1);
}

void	render_image(t_img_data *data)
{
	double	x_step;
	double	y_step;
	double	x_tmp;
	double	y_tmp;
	int		x;
	int		y;

	x_step = 3 / (double)WIN_WIDTH;
	y_step = 2 / (double)WIN_HEIGHT;
	y = 0;
	y_tmp = 1;

	while (y < WIN_HEIGHT / 2)
	{
		x = 0;

		x_tmp = -2;
		while (x < WIN_WIDTH)
		{
			if (check_belongings(x_tmp, y_tmp) == 0)
			{
				my_mlx_pixel_put(data, x, y, 0x00FFFFFF);
				my_mlx_pixel_put(data, x, WIN_HEIGHT - y - 1, 0x00FFFFFF);
			}
			x_tmp += x_step;
			x++;
		}
		y_tmp -= y_step;
		y++;
	}
}

int	my_close(int keycode, t_all *all)
{
	if (keycode == 53)
		my_close_x(all);
	return (1);
}

void	mlx_start(t_all *all)
{
	int	screen_height;
	int	screen_width;

	all->mlx = mlx_init();

	mlx_get_screen_size(all->mlx, &screen_width, &screen_height);
	if (WIN_HEIGHT > screen_height || WIN_HEIGHT < 320 || WIN_WIDTH >
	        screen_width || WIN_WIDTH < 320)
		exit(777);

	all->mlx_win = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	all->mlx_image = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img_data->addr = mlx_get_data_addr(all->mlx_image,
											&all->img_data->bits_per_pixel,
											&all->img_data->line_length,
											&all->img_data->endian);
	all->img_data->bytes_per_pixel = all->img_data->bits_per_pixel / 8;

	//TODO: render an image
	render_image(all->img_data);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);

	mlx_hook(all->mlx_win, 2, 1L<<0, my_close, all);
	mlx_hook(all->mlx_win, 17, 1L<<16, my_close_x, all);
	mlx_loop(all->mlx);
}
