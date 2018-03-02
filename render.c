/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:46:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/22 16:46:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	render(t_app *app)
{
	int			i;
	int			j;
	t_vector	temp;

	free_map(app->transformed);
	app->transformed = malloc(sizeof(t_map));
	app->transformed->lines = app->map->lines;
	app->transformed->linesize = app->map->linesize;
	app->transformed->map = (t_vertex**)malloc(sizeof(t_vertex*) * app->
			transformed->lines + 1);
	i = -1;
	while (++i < app->transformed->lines)
	{
		j = -1;
		app->transformed->map[i] = (t_vertex*)malloc(sizeof(t_vertex) * app->
				transformed->linesize);
		while (++j < app->transformed->linesize)
		{
			temp = (t_vector){j - app->map->linesize / 2, i -
				app->map->lines / 2, app->map->map[i][j].vector[2] -
				(app->map->maxz - app->map->minz) / 2, 1};
			app->transformed->map[i][j].vector = transform(app, temp);
			app->transformed->map[i][j].color = app->map->map[i][j].color;
		}
	}
}
