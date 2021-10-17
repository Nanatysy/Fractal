//
// Created by Debby Willette on 10/16/21.
//

#include "fractol.h"

//void	render_image_d(t_img_data *data, double cx, double cy)
//{
//	t_mlx_coord	c;
//
//	c.x_step = data->info->cur_width / (double)WIN_WIDTH;
//	c.y_step = data->info->cur_height / (double)WIN_HEIGHT;
//	c.y = 0;
//	c.y_tmp = data->info->y_corner;
//	while (c.y < WIN_HEIGHT)
//	{
//		c.x = 0;
//		c.x_tmp = data->info->x_corner;
//		while (c.x < WIN_WIDTH)
//		{
//			c.res = data->f_bel[data->set](c.x_tmp, c.y_tmp, cx, cy);
//			if (data->color_table[data->index_c][c.res] == -1)
//				data->color_table[data->index_c][c.res] = data->f[data->index_c]
//						(c.res, data->pow_4, data->pow_2);
//			my_mlx_pixel_put(data, c.x, c.y, data->color_table[data->index_c]
//			[c.res]);
//			c.x_tmp += c.x_step;
//			c.x++;
//		}
//		c.y_tmp += c.y_step;
//		c.y++;
//	}
//}
