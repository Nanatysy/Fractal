//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"

int print_errors(int flag)
{
	if (flag == ARG_NUM_ERROR)
		printf("Wrong number of arguments. Please specify which set you want "
			   "to see:\nJulia set or Mandelbrot set.\n");
	return (0);
}