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

# define MAX_ITERATIONS 250

# define ARG_NUM_ERROR "wrong number of arguments."
# define JULIA 1
# define MANDELBROT 2
# define WRONG_SET "wrong set."

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
	int			index;
	int			(*f[3])(int);
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			line_length;
	int			endian;
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
void	render_image_m(t_img_data *data);
void	render_image_j(t_img_data *data, double cx, double cy);
void	init_coord_structure(t_coord_info *data, int flag);
double	ft_atof(const char *arg);
int		my_close_x(t_all *all);
int		my_close(int keycode, t_all *all);
int		moise_catch(int button, int x, int y, t_all *all);
int		check_belongings_m(double x, double y);
int		check_belongings_j(double x, double y, double cx, double cy);
int		check_belong_to_cardioid(double x, double y);
int		find_color_blue_and_yellow(int iter);
int		find_color_rainbow(int iter);
int		find_color_pink_and_green(int iter);
int		print_errors(char *flag);

// bonus part
void	mlx_start_bonus(t_all *all);
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
