/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:22:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/15 19:22:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	rotate_0x(t_vector vector, double angle)
{
	t_vector res;

	res[0] = vector[0];
	res[1] = vector[1] * cos(angle) - vector[2] * sin(angle);
	res[2] = vector[1] * sin(angle) + vector[2] * cos(angle);
	res[3] = vector[3];
	return (res);
}

t_vector	rotate_0y(t_vector vector, double angle)
{
	t_vector res;

	res[0] = vector[0] * cos(angle) + vector[2] * sin(angle);
	res[1] = vector[1];
	res[2] = vector[0] * -sin(angle) + vector[2] * cos(angle);
	res[3] = vector[3];
	return (res);
}

t_vector	rotate_0z(t_vector vector, double angle)
{
	t_vector res;

	res[0] = vector[0] * cos(angle) - vector[1] * sin(angle);
	res[1] = vector[0] * sin(angle) + vector[1] * cos(angle);
	res[2] = vector[2];
	res[3] = vector[3];
	return (res);
}

t_vector	rotate(t_app *app, t_vector vector)
{
	return (rotate_0z(rotate_0y(rotate_0x(vector,
			app->cam.a), app->cam.b), app->cam.g));
}
