//
// Created by Debby Willette on 9/18/21.
//

#ifndef FRACTOL_H
#define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>

# define ARG_NUM_ERROR 1
# define JULIA 2
# define MANDELBROT 3
# define WRONG_SET 4

typedef struct	s_all {
	int			set;
}				t_all;

int print_errors(int flag);

#endif //FRACTOL_H
