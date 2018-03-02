/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:23:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/15 19:23:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	projection(t_app *app, t_vector vector)
{
	t_vector res;

	res[0] = vector[0] / vector[3];
	res[1] = vector[1] / vector[3];
	res[2] = vector[2] / vector[3];
	res[3] = vector[3];
	app = (void*)app;
	return (res);
}

t_vector	scale(t_app *app, t_vector vector)
{
	t_vector res;

	res[0] = app->cam.scale * vector[0];
	res[1] = app->cam.scale * vector[1];
	res[2] = app->cam.scale * vector[2];
	res[3] = vector[3];
	return (res);
}

t_vector	shift(t_app *app, t_vector vector)
{
	t_vector res;

	res[0] = vector[0] + vector[3] * app->cam.xshift;
	res[1] = vector[1] + vector[3] * app->cam.yshift;
	res[2] = vector[2];
	res[3] = vector[3];
	return (res);
}

t_vector	transform(t_app *app, t_vector vector)
{
	return (projection(app, shift(app, scale(app, rotate(app, vector)))));
}
