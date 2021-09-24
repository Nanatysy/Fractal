//
// Created by Debby Willette on 9/24/21.
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
