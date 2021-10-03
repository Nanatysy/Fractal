//
// Created by Debby Willette on 10/1/21.
//

#include "fractol.h"

int	find_color_rainbow(int iter, int pow_4, int pow_2)
{
	t_color	c;
	int		step;

	init_colors(&c.red, &c.green, &c.blue);
	find_step(5, &step);
	if (iter < step * 3)
		rainbow_first(&c, iter, step);
	else if (iter < step * 4)
	{
		iter -= step * 3;
		c.green = 255 - iter * 255 / step;
		c.blue = 255;
	}
	else
	{
		iter -= step * 4;
		c.blue = 255 - iter * 255 / step;
	}
	return (c.red * pow_4 + c.green * pow_2 + c.blue);
}

int	find_color_blue_and_yellow(int iter, int pow_4, int pow_2)
{
	t_color	c;
	int		step;

	init_colors(&c.red, &c.green, &c.blue);
	find_step(4, &step);
	iter = MAX_ITERATIONS - iter;
	if (iter < step * 2)
		blue_and_yellow_first(&c, iter, step);
	else if (iter < step * 3)
	{
		iter -= step * 2;
		c.red = 255 - iter * 255 / step;
		c.green = 255 - iter * 255 / step;
		c.blue = 255;
	}
	else
	{
		iter -= step * 3;
		c.blue = 255 - iter * 127 / step;
	}
	return (c.red * pow_4 + c.green * pow_2 + c.blue);
}

int	find_color_pink_and_green(int iter, int pow_4, int pow_2)
{
	t_color	c;
	int		step;

	init_colors(&c.red, &c.green, &c.blue);
	find_step(5, &step);
	if (iter < step * 3)
		pink_and_green_first(&c, iter, step);
	else if (iter < step * 4)
	{
		iter -= step * 3;
		c.red = 152 - iter * 152 / step;
		c.green = 251 + iter * 4 / step;
		c.blue = 152 - iter * 25 / step;
	}
	else
	{
		iter -= step * 4;
		c.green = 255 - iter * 255 / step;
		c.blue = 127 - iter * 127 / step;
	}
	return (c.red * pow_4 + c.green * pow_2 + c.blue);
}
