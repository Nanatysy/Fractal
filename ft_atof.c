//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

double	ft_atof(const char *arg)
{
	double	res;
	int		tmp;
	int		i;
	int		j;

	tmp = ft_atoi(arg);
	i = 0;
	while (arg[i] != '.' && arg[i] != '\0')
		i++;
	if (arg[i] == '\0')
		return ((double)tmp);
	res = (double)tmp;
	tmp = ft_atoi(&arg[++i]);
	j = 0;
	while (ft_isdigit(arg[i++]))
		j++;
	if (res < 0)
		res -= (double)tmp / pow(10, j);
	else
		res += (double)tmp / pow(10, j);
	return (res);
}
