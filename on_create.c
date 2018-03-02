/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 21:00:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/15 21:00:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	on_create(t_app *app)
{
	app->helpenabled = 0;
	app->guienabled = 1;
	app->cam.scale = 25;
	app->cam.xshift = WINDOW_W / 2;
	app->cam.yshift = WINDOW_H / 2;
	app->cam.a = 0;
	app->cam.b = 0;
	app->cam.g = 0;
	app->cam.focus = 2;
}
