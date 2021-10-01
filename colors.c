//
// Created by Debby Willette on 10/1/21.
//

#include "fractol.h"

int	find_color_rainbow(int iter)
{
	int	red;
	int	green;
	int	blue;
	int	step;

	init_colors(&red, &green, &blue);
	if (MAX_ITERATIONS % 5 != 0)
		step = (MAX_ITERATIONS + 5) / 4;
	else
		step = MAX_ITERATIONS / 4;

	if (iter < step)
	{
		red = 255;
		green = iter * 255 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 255 - iter * 255 / step;
		green = 255;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		green = 255;
		blue = iter * 255 / step;
	}
	else if (iter < step * 4)
	{
		iter -= step * 3;
		green = 255 - iter * 255 / step;
		blue = 255;
	}
	else
	{
		iter -= step * 4;
		blue = 255 - iter * 255 / step;

	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}

int	find_color_blue_and_yellow(int iter)
{
	int	red;
	int	green;
	int	blue;
	int	step;

	init_colors(&red, &green, &blue);
	if (MAX_ITERATIONS % 4 != 0)
		step = (MAX_ITERATIONS + 4) / 4;
	else
		step = MAX_ITERATIONS / 4;

	iter = MAX_ITERATIONS - iter;

	if (iter < step)
	{
		red = iter * 255 / step;
		green = iter * 200 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 255;
		green = 200 + iter * 55 / step;
		blue = iter * 255 / step;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		red = 255 - iter * 255 / step;
		green = 255 - iter * 255 / step;
		blue = 255;
	}
	else
	{
		iter -= step * 3;
		blue = 255 - iter * 127 / step;
	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}

int	find_color_pink_and_green(int iter)
{
	int	red;
	int	green;
	int	blue;
	int	step;

	init_colors(&red, &green, &blue);
	if (MAX_ITERATIONS % 4 != 0)
		step = (MAX_ITERATIONS + 4) / 4;
	else
		step = MAX_ITERATIONS / 4;

	if (iter < step)
	{
		red = 220 + iter * 20 / step;
		green = 20 + iter * 108 / step;
		blue = 60 + iter * 68 / step;
	}
	else if (iter < step * 2)
	{
		iter -= step;
		red = 240 + iter * 15 / step;
		green = 128 + iter * 127 / step;
		blue = 128 + iter * 127 / step;
	}
	else if (iter < step * 3)
	{
		iter -= step * 2;
		red = 255 - iter * 103 / step;
		green = 255 - iter * 4 / step;
		blue = 255 - iter * 103 / step;
	}
	else
	{
		iter -= step * 3;
		red = 152 - iter * 152 / step;
		green = 251 + iter * 4 / step;
		blue = 152 - iter * 25 / step;
	}
	return (red * (int)pow(16, 4) + green * (int)pow(16, 2) + blue);
}
