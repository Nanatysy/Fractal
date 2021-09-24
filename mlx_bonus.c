//
// Created by Debby Willette on 9/22/21.
//

#include "fractol.h"

int	key_press(int keycode, t_all *all)
{
	// 123 <-
	// 124 ->
	// 125 down
	// 126 up

	if (keycode == 123)
		all->img_data->info->x_corner -= all->img_data->info->cur_width * 0.05
				/ 2;
	else if (keycode == 124)
		all->img_data->info->x_corner += all->img_data->info->cur_width * 0.05
										 / 2;
	else if (keycode == 125)
		all->img_data->info->y_corner -= all->img_data->info->cur_height * 0.05
										 / 2;
	else if (keycode == 126)
		all->img_data->info->y_corner += all->img_data->info->cur_height * 0.05
										 / 2;
	else if (keycode == 53)
		my_close_x(all);

	if (all->set == MANDELBROT)
		render_image_m(all->img_data);
	else
		render_image_j(all->img_data);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
	mlx_do_sync(all->mlx);
	return (0);
}

int	moise_catch_bonus(int button, int x, int y, t_all *all)
{
	double	tmp; // delete
	double	x_tmp;
	double	y_tmp;

	mlx_mouse_get_pos(all->mlx_win, &x, &y);

	x_tmp = all->img_data->info->x_corner + (x *
			all->img_data->info->cur_width) / WIN_WIDTH;
	y_tmp = all->img_data->info->y_corner - (y *
			all->img_data->info->cur_height) / WIN_HEIGHT;

	// x, y - wrong coord sys - change

	all->img_data->info->x_corner += (x_tmp - all->img_data->info->x0) * 0.05;
	all->img_data->info->x0 += (x_tmp - all->img_data->info->x0) * 0.05;
	all->img_data->info->y_corner += (y_tmp - all->img_data->info->y0) * 0.05;
	all->img_data->info->y0 += (y_tmp - all->img_data->info->y0) * 0.05;

	if (button == 5)
	{
		tmp = all->img_data->info->cur_height * 0.05;
		all->img_data->info->y_corner -= tmp / 2;
		all->img_data->info->cur_height -= tmp;
		tmp = all->img_data->info->cur_width * 0.05;
		all->img_data->info->cur_width -= tmp;
		all->img_data->info->x_corner += tmp / 2;
		if (all->set == MANDELBROT)
			render_image_m(all->img_data);
		else
			render_image_j(all->img_data);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}
	if (button == 4)
	{
		tmp = all->img_data->info->cur_height * 0.05;
		all->img_data->info->y_corner += tmp / 2;
		all->img_data->info->cur_height += tmp;
		tmp = all->img_data->info->cur_width * 0.05;
		all->img_data->info->x_corner -= tmp / 2;
		all->img_data->info->cur_width += tmp;
		if (all->set == MANDELBROT)
			render_image_m(all->img_data);
		else
			render_image_j(all->img_data);
		mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);
		mlx_do_sync(all->mlx);
	}

	return (0);
}

