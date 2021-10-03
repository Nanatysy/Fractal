//
// Created by Debby Willette on 10/2/21.
//

#include "fractol.h"

int	check_belongings_s(double x, double y, double tmp1, double tmp2)
{
	int		i;
	double	xn;
	double	yn;
	double	tmp;

	i = 0;
	xn = x;
	yn = y;
	while (i < MAX_ITERATIONS)
	{
		tmp = xn * xn - yn * yn + x;
		yn = 2 * fabs(xn * yn) + y;
		xn = tmp;
		if (xn * xn + yn * yn >= 4)
			return (i);
		i++;
	}
	(void)tmp1;
	(void)tmp2;
	return (i);
}
