//
// Created by Debby Willette on 9/21/21.
//

#include "fractol.h"

int	check_belong_to_cardioid(double x, double y)
{
	double	teta;
	double	quarter;
	double	half;

	quarter = 1. / 4;
	half = 1. / 2;
	teta = atan2(y, x - quarter);
	if (sqrt(pow((x - quarter), 2) + pow(y, 2)) <= half - half * cos(teta))
		return (1);
	return (0);
}

int	check_belongings_m(double x, double y, double tmp1, double tmp2)
{
	int		i;
	double	xn;
	double	yn;
	double	tmp;

	i = 0;
	xn = x;
	yn = y;
	if (check_belong_to_cardioid(x, y) == 1)
		return (MAX_ITERATIONS);
	while (i < MAX_ITERATIONS)
	{
		tmp = xn * xn - yn * yn + x;
		yn = 2 * xn * yn + y;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	(void)tmp1;
	(void)tmp2;
	return (i);
}
