/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:03:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/09 21:03:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal(t_app *app)
{
	int i;
	int r;

	r = 0;
	while (r < app->map->lines)
	{
		i = 0;
		while (i < app->map->linesize - 1)
		{
			img_draw_line(app,
				app->transformed->map[r][i], app->transformed->map[r][i + 1]);
			i++;
		}
		r++;
	}
}

void	draw_vertical(t_app *app)
{
	int i;
	int r;

	r = 0;
	while (r < app->transformed->lines - 1)
	{
		i = 0;
		while (i < app->transformed->linesize)
		{
			img_draw_line(app,
							app->transformed->map[r][i],
							app->transformed->map[r + 1][i]);
			i++;
		}
		r++;
	}
}

void	draw_map(t_app *app)
{
	mlx_destroy_image(app->mlx, app->image);
	app->image = mlx_new_image(app->mlx, WINDOW_W, WINDOW_H);
	render(app);
	draw_horizontal(app);
	draw_vertical(app);
	mlx_put_image_to_window(app->mlx, app->window, app->image, 0, 0);
	draw_menu(app);
}
