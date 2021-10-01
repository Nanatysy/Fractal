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
		printf("Julia set or Mandelbrot set.\n");
	}
	return (0);
}

void	free_and_exit(t_all *all, char *flag)
{
	print_errors(flag);
	if (all->img_data)
	{
		if (all->img_data->info)
			free(all->img_data->info);
		free(all->img_data);
	}
	exit(0);
}
