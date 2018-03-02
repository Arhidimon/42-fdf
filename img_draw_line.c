/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:03:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 19:03:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mixcolors(float f1, float f2, t_point color)
{
	unsigned char r;
	unsigned char g;
	unsigned char b;

	r = (unsigned char)((float)(((color.x >> 16) & 0x0000FF)) * f1 +
			((float)((color.y >> 16) & 0x0000FF)) * f2);
	g = (unsigned char)(((float)((color.x >> 8) & 0x0000FF)) * f1 +
			((float)((color.y >> 8) & 0x0000FF)) * f2);
	b = (unsigned char)(((float)(color.x & 0x0000FF)) * f1 +
			((float)(color.y & 0x0000FF)) * f2);
	return (rgb_to_int(r, g, b));
}

int		gradient(t_point a, t_point b, t_point p, t_point color)
{
	float f1;
	float f2;

	a.x = p.x - a.x;
	a.y = p.y - a.y;
	b.x = b.x - p.x;
	b.y = b.y - p.y;
	if (ABS((b.x + a.x)) > ABS((b.y + a.y)))
	{
		if (a.x + b.x == 0)
			return (color.x);
		f1 = a.x / (float)(a.x + b.x);
		f2 = 1 - f1;
	}
	else
	{
		if (a.y + b.y == 0)
			return (color.x);
		f1 = a.y / (float)(a.y + b.y);
		f2 = 1 - f1;
	}
	return (mixcolors(f2, f1, color));
}

void	move_point(int *d1, int *d2, int *s1, int *s2)
{
	*d1 += *s1;
	*d2 += *s2;
}

void	plot_line(t_app *app, t_point a, t_point b, t_point color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;
	t_point	start;

	start = a;
	d = get_point(ABS((b.x - a.x)), -ABS((b.y - a.y)));
	s = get_point((a.x < b.x) ? 1 : -1, (a.y < b.y) ? 1 : -1);
	err = d.x + d.y;
	while (1)
	{
		if (app->cam.gradient)
			img_pixel_plot(app->image, get_point(a.x, a.y),
							gradient(start, b, a, color));
		else
			img_pixel_plot(app->image, get_point(a.x, a.y), color.x);
		if (a.x == b.x && a.y == b.y)
			break ;
		e2 = 2 * err;
		if (e2 >= d.y)
			move_point(&err, &(a.x), &(d.y), &(s.x));
		if (e2 <= d.x)
			move_point(&err, &(a.y), &(d.x), &(s.y));
	}
}

void	img_draw_line(t_app *app, t_vertex a, t_vertex b)
{
	plot_line(app, get_point((int)(A_X), (int)(A_Y)),
				get_point((int)(B_X), (int)(B_Y)),
				get_point(a.color, b.color));
}
