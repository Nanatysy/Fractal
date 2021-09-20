//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"

int print_errors(char *flag)
{
	printf("%sError: %s%s\n", RED, NONE, flag);
	if (!ft_strncmp(flag, ARG_NUM_ERROR, ft_strlen(ARG_NUM_ERROR)) ||
	!ft_strncmp(flag, WRONG_SET, ft_strlen(WRONG_SET)))
		printf("Please specify which set you want to see:\nJulia set or Mandelbrot set.\n");
	return (0);
}