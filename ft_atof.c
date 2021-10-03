//
// Created by Debby Willette on 9/24/21.
//

#include "fractol.h"

int	is_neg(const char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || (arg[i] >= 9 && arg[i] <= 13))
		i++;
	if (arg[i] == '-')
		return (1);
	return (0);
}

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
	while (ft_isdigit(arg[i++]) && j < 9)
		j++;
	if (is_neg(arg))
		res -= (double)tmp / pow(10, j);
	else
		res += (double)tmp / pow(10, j);
	return (res);
}
