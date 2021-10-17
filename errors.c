//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"

int	print_errors(char *flag)
{
	printf("%sError: %s%s\n", RED, NONE, flag);
	if (!ft_strncmp(flag, ARG_NUM_ERROR, ft_strlen(ARG_NUM_ERROR)) || \
		!ft_strncmp(flag, WRONG_SET, ft_strlen(WRONG_SET)))
	{
		printf("Please specify which set you want to see:\n");
		printf("Julia set or Mandelbrot set for mandatory part.\n");
		printf("Julia set, Mandelbrot set, Burning ship set or Dynamic Julia "
			   "set for bonus part.\n");
	}
	return (0);
}

void	free_and_exit(t_all *all, char *flag)
{
	int	i;

	i = 0;
	print_errors(flag);
	if (all->img_data)
	{
		while (i < 3)
		{
			if (all->img_data->color_table[i])
				free(all->img_data->color_table[i]);
			i++;
		}
		if (all->img_data->info)
			free(all->img_data->info);
		free(all->img_data);
	}
	exit(0);
}

void	init_color_table(t_img_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j <= MAX_ITERATIONS)
			data->color_table[i][j++] = -1;
		i++;
	}
}
