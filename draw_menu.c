/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:47:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 17:47:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_app *app)
{
	if (app->nogui || !app->guienabled)
		return ;
	if (app->helpenabled)
		mlx_put_image_to_window(app->mlx, app->window, app->guihelp, 0, 0);
	else
		mlx_put_image_to_window(app->mlx, app->window, app->gui, 0, 0);
}
