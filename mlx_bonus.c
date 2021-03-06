//
// Created by Debby Willette on 9/22/21.
//

#include "fractol.h"

int	key_press(int keycode, t_all *all)
{
	static int	tmp;

	if (keycode == 123)
		all->img_data->info->x_corner -= all->img_data->info->cur_width * 0.05
			/ 2;
	else if (keycode == 124)
		all->img_data->info->x_corner += all->img_data->info->cur_width * 0.05
			 / 2;
	else if (keycode == 125)
		all->img_data->info->y_corner += all->img_data->info->cur_height * 0.05
			 / 2;
	else if (keycode == 126)
		all->img_data->info->y_corner -= all->img_data->info->cur_height * 0.05
			 / 2;
	else if (keycode == 53)
		my_close_x(all);
	else if (keycode == 36)
		all->img_data->index_c = ++tmp % 3;
	render_image(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

void	show_color_map(t_img_data *data)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		color = find_color_pink_and_green(x * MAX_ITERATIONS / WIN_WIDTH,
				   data->pow_4, data->pow_2);
		while (y < WIN_HEIGHT)
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}

void	zoom_in_bonus(t_all *all)
{
	double	tmp;

	tmp = all->img_data->info->cur_height * 0.15;
	all->img_data->info->y_corner += tmp / 2;
	all->img_data->info->cur_height -= tmp;
	tmp = all->img_data->info->cur_width * 0.15;
	all->img_data->info->cur_width -= tmp;
	all->img_data->info->x_corner += tmp / 2;
	render_image(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
}

void	zoom_out_bonus(t_all *all)
{
	double	tmp;

	tmp = all->img_data->info->cur_height * 0.15;
	all->img_data->info->y_corner -= tmp / 2;
	all->img_data->info->cur_height += tmp;
	tmp = all->img_data->info->cur_width * 0.15;
	all->img_data->info->x_corner -= tmp / 2;
	all->img_data->info->cur_width += tmp;
	render_image(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
}

int	moise_catch_bonus(int button, int x, int y, t_all *all)
{
	double	x_tmp;
	double	y_tmp;

	mlx_mouse_get_pos(all->mlx_win, &x, &y);
	x_tmp = all->img_data->info->x_corner + (x * \
			all->img_data->info->cur_width) / WIN_WIDTH;
	y_tmp = all->img_data->info->y_corner + (y * \
			all->img_data->info->cur_height) / WIN_HEIGHT;
	all->img_data->info->x_corner += (x_tmp - all->img_data->info->x0) * 0.15;
	all->img_data->info->x0 += (x_tmp - all->img_data->info->x0) * 0.15;
	all->img_data->info->y_corner += (y_tmp - all->img_data->info->y0) * 0.15;
	all->img_data->info->y0 += (y_tmp - all->img_data->info->y0) * 0.15;
	if (button == 5)
		zoom_in_bonus(all);
	if (button == 4)
		zoom_out_bonus(all);
	return (0);
}
