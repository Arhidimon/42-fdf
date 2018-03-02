/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 20:03:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/01 20:03:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_app	get_app(void *mlx)
{
	t_app		app;
	int			w;
	int			h;

	app.mlx = mlx;
	app.window = mlx_new_window(mlx, WINDOW_W, WINDOW_H,
								"FDF by dbezruch aka Arhidimon");
	app.image = mlx_new_image(mlx, WINDOW_W, WINDOW_H);
	if (access(SKIN, R_OK) || access(SKINHELP, R_OK))
		app.nogui = 1;
	else
	{
		app.gui = mlx_xpm_file_to_image(mlx, SKIN, &w, &h);
		app.guihelp = mlx_xpm_file_to_image(mlx, SKINHELP, &w, &h);
		app.nogui = 0;
	}
	return (app);
}
