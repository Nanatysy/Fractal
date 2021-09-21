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

# define ARG_NUM_ERROR "wrong number of arguments."
# define JULIA 1
# define MANDELBROT 2
# define WRONG_SET "wrong set."

typedef struct	s_img_data
{
//	void		*mlx_image;
	double		x_corner;
	double		y_corner;
	char		*addr;
	int			bits_per_pixel;
	int			bytes_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct	s_all {
	int			set;
	void		*mlx;
	void		*mlx_win;
	void		*mlx_image;
	t_img_data	*img_data;
}				t_all;

void	mlx_start(t_all *all);
void	my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void	render_image_m(t_img_data *data);
void	render_image_j(t_img_data *data);
int		my_close_x(t_all *all);
int		my_close(int keycode, t_all *all);
int		check_belongings_m(double x, double y);
int		check_belong_to_cardioid(double x, double y);
int		print_errors(char *flag);

#endif //FRACTOL_H
