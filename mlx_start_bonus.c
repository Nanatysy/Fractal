//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

void	mlx_start_bonus(t_all *all)
{
	int	screen_height;
	int	screen_width;

	all->mlx = mlx_init();
	all->img_data->index = 0;
	all->img_data->f[0] = &find_color_rainbow;
	all->img_data->f[1] = &find_color_blue_and_yellow;
	all->img_data->f[2] = &find_color_pink_and_green;

	mlx_get_screen_size(all->mlx, &screen_width, &screen_height);
	if (WIN_HEIGHT > screen_height || WIN_HEIGHT < 320 || WIN_WIDTH >
														  screen_width || WIN_WIDTH < 320)
		exit(777); // TODO: write good looking error message

	all->mlx_win = mlx_new_window(all->mlx, WIN_WIDTH, WIN_HEIGHT, "fractol");
	all->mlx_image = mlx_new_image(all->mlx, WIN_WIDTH, WIN_HEIGHT);
	all->img_data->addr = mlx_get_data_addr(all->mlx_image,
											&all->img_data->bits_per_pixel,
											&all->img_data->line_length,
											&all->img_data->endian);
	all->img_data->bytes_per_pixel = all->img_data->bits_per_pixel / 8;

	init_coord_structure(all->img_data->info, all->set);

	if (all->set == MANDELBROT)
		render_image_m(all->img_data);
	else
		render_image_j(all->img_data, all->cx, all->cy);
	mlx_put_image_to_window(all->mlx, all->mlx_win, all->mlx_image, 0, 0);

	printf("If you want to change fractol color, please press ENTER\n");

	mlx_hook(all->mlx_win, 2, 1L<<0, key_press, all);
	mlx_hook(all->mlx_win, 17, 1L<<16, my_close_x, all);
	mlx_mouse_hook(all->mlx_win, moise_catch_bonus, all);

	mlx_loop(all->mlx);


}


