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
		data->y_corner = -1;
		data->cur_height = 2;
		data->cur_width = 3;
		data->x0 = -0.5;
		data->y0 = 0;
	}
	else
	{
		data->x_corner = -3;
		data->y_corner = -2;
		data->cur_height = 4;
		data->cur_width = 6;
		data->x0 = 0;
		data->y0 = 0;
	}
}

void	init_struct(t_all *all)
{
	int	i;

	i = 0;
	all->img_data = malloc(sizeof(t_img_data));
	if (!all->img_data)
		free_and_exit(all, MALLOC_ERROR);
	all->img_data->pow_4 = (int) pow(16, 4);
	all->img_data->pow_2 = (int) pow(16, 2);
	all->img_data->color_table[0] = all->img_data->rainbow;
	all->img_data->color_table[0] = all->img_data->blue_and_yellow;
	all->img_data->color_table[0] = all->img_data->pink_and_green;
	while (i < 3)
	{
		all->img_data->color_table[i++] = malloc(sizeof(int) * \
			MAX_ITERATIONS + 1);
	}
	all->img_data->info = NULL;
	if (!all->img_data->color_table[0] || !all->img_data->color_table[1] || \
		!all->img_data->color_table[2])
		free_and_exit(all, MALLOC_ERROR);
	init_color_table(all->img_data);
	all->img_data->info = malloc(sizeof(t_coord_info));
	if (!all->img_data->info)
		free_and_exit(all, MALLOC_ERROR);
}
