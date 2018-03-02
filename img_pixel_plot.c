/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_pixel_plot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:28:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 19:28:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pixel_plot(void *image, t_point a, int color)
{
	int endian;
	int sizeline;
	int bpp;
	int *imgcontent;

	if (a.x < 0 || a.y < 0 || a.x >= WINDOW_W || a.y >= WINDOW_H)
		return ;
	imgcontent = (int*)mlx_get_data_addr(image, &bpp, &sizeline, &endian);
	imgcontent[a.x + a.y * sizeline / 4] = color;
}
