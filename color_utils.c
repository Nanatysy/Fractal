//
// Created by Debby Willette on 10/1/21.
//

#include "fractol.h"

void	init_colors(int *red, int *green, int *blue)
{
	*red = 0;
	*green = 0;
	*blue = 0;
}

void	find_step(int num, int *step)
{
	if (MAX_ITERATIONS % num != 0)
		*step = (MAX_ITERATIONS + num) / num;
	else
		*step = MAX_ITERATIONS / num;
}

void	rainbow_first(t_color *c, int iter, int step)
{
	if (iter < step)
	{
		c->red = 255;
		c->green = iter * 255 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		c->red = 255 - iter * 255 / step;
		c->green = 255;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		c->green = 255;
		c->blue = iter * 255 / step;
	}
}

void	blue_and_yellow_first(t_color *c, int iter, int step)
{
	if (iter < step)
	{
		c->red = iter * 255 / step;
		c->green = iter * 200 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		c->red = 255;
		c->green = 200 + iter * 55 / step;
		c->blue = iter * 255 / step;
	}
}

void	pink_and_green_first(t_color *c, int iter, int step)
{
	if (iter < step)
	{
		c->red = 220 + iter * 20 / step;
		c->green = 20 + iter * 108 / step;
		c->blue = 60 + iter * 68 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		c->red = 240 + iter * 15 / step;
		c->green = 128 + iter * 127 / step;
		c->blue = 128 + iter * 127 / step;
	}
}
