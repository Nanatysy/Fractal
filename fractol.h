//
// Created by Debby Willette on 9/18/21.
//

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h> // malloc, free, exit
# include <stdio.h> // printf
# include <fcntl.h> // open
# include <unistd.h> // close, write, read
# include <math.h>
# include "./libft/libft.h"
# include "./minilibX/mlx.h"

# define RED "\x1b[31m"
# define NONE "\x1b[0m"

# define WIN_HEIGHT 800
# define WIN_WIDTH 1200

# define MAX_ITERATIONS 200

# define ARG_NUM_ERROR "wrong number of arguments."
# define ARG_NUM_ERROR_J "wrong number of arguments to output Julia set."
# define WRONG_SET "wrong set."
# define MALLOC_ERROR "failed to allocate memory."
# define SCREEN_SIZE "invalid screen size."

# define JULIA 0
# define MANDELBROT 1
# define SHIP 2
# define DYNAMIC_J 3
# define W_SET 4

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_mlx_coord
{
	double		x_step;
	double		y_step;
	double		x_tmp;
	double		y_tmp;
	int			x;
	int			y;
	int			res;
}				t_mlx_coord;

typedef struct	s_coord_info
{
	double		x_corner;
	double		y_corner;
	double		cur_height;
	double		cur_width;
	double		x0;
	double		y0;
}				t_coord_info;

typedef struct	s_img_data
{
	t_coord_info	*info;
	int			index_c;
	int			set;
	int			(*f[3])(int, int, int);
	int			(*f_bel[3])(double, double, double, double);
	int			*color_table[3];
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			line_length;
	int			endian;
	int			pow_4;
	int			pow_2;
	int			*rainbow;
	int			*blue_and_yellow;
	int			*pink_and_green;
}				t_img_data;

typedef struct	s_all {
	int			set;
	double		cx;
	double		cy;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	t_img_data	*img_data;
}				t_all;

void	mlx_start(t_all *all);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	my_mlx_loop(t_all *all);
void	zoom_in(t_all *all);
void	zoom_out(t_all *all);
void	render_image(t_img_data *data, double cx, double cy);
void	render_image_m(t_img_data *data);
void	render_image_j(t_img_data *data, double cx, double cy);
void	render_image_s(t_img_data *data);
void	init_coord_structure(t_coord_info *data, int flag);
void	init_colors(int *red, int *green, int *blue);
void	init_color_table(t_img_data *data);
void	init_struct(t_all *all);
void	find_step(int num, int *step);
void	free_and_exit(t_all *all, char *flag);
double	ft_atof(const char *arg);
int		my_close_x(t_all *all);
int		my_close(int keycode, t_all *all);
int		moise_catch(int button, int x, int y, t_all *all);
int		check_belongings_m(double x, double y, double tmp1, double tmp2);
int		check_belongings_j(double x, double y, double cx, double cy);
int		check_belongings_s(double x, double y, double tmp1, double tmp2);
int		check_belong_to_cardioid(double x, double y);
int		find_color_blue_and_yellow(int iter, int pow_4, int pow_2);
int		find_color_rainbow(int iter, int pow_4, int pow_2);
int		find_color_pink_and_green(int iter, int pow_4, int pow_2);
int		print_errors(char *flag);

void	rainbow_first(t_color *c, int iter, int step);
void	blue_and_yellow_first(t_color *c, int iter, int step);
void	pink_and_green_first(t_color *c, int iter, int step);

// bonus part
void	mlx_start_bonus(t_all *all);
void	my_mlx_loop_bonus(t_all *all);
void	bonus_init(t_all *all);
void	show_color_map(t_img_data *data);
int		key_press(int keycode, t_all *all);
int		moise_catch_bonus(int button, int x, int y, t_all *all);

/*
	double	cx = 0.14096943887775515;
	double	cy = 0.5995240480961923;

	double	cx = -0.8021167334669339;
	double	cy = 0.2497745490981964;

 	double	cx = 0.355;
	double	cy = 0.355;

	double	cx = -0.4;
	double	cy = -0.59;

	double	cx = -0.75;
	double	cy = 0.2;

	double	cx = -0.4;
	double	cy = 0.6
 */

#endif //FRACTOL_H
