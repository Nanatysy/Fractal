//
// Created by Debby Willette on 9/18/21.
//

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_all all;
	if (argc < 2)
		return (print_errors(ARG_NUM_ERROR));

	// check argv[1], it should 1 of 2 sets
	(void)argv;
	all.set = 2;

	return (0);
}