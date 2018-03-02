/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 00:56:50 by dbezruch          #+#    #+#             */
/*   Updated: 2018/03/02 00:56:54 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "fdf.h"
#include "keys.h"
#include <stdlib.h>

void	seppuku(int code, char *lastworld)
{
	if (code)
	{
		if (lastworld)
			perror(lastworld);
	}
	else if (lastworld)
		ft_putendl(lastworld);
	exit(0);
}

int		close_click(void)
{
	seppuku(0, 0);
	return (0);
}

void	key_handler_rotate(int key, t_app *param)
{
	if (key == KEY_S)
		param->cam.a -= ROTATION_SPEED;
	if (key == KEY_W)
		param->cam.a += ROTATION_SPEED;
	if (key == KEY_A)
		param->cam.b -= ROTATION_SPEED;
	if (key == KEY_D)
		param->cam.b += ROTATION_SPEED;
	if (key == KEY_Q)
		param->cam.g -= ROTATION_SPEED;
	if (key == KEY_E)
		param->cam.g += ROTATION_SPEED;
}

int		key_handler(int key, t_app *param)
{
	if (key == KEY_A || key == KEY_D || key == KEY_W || key == KEY_S ||
			key == KEY_Q || key == KEY_E)
		key_handler_rotate(key, param);
	else if (key == KEY_SPACE)
		param->helpenabled = (param->helpenabled == 0 ? 1 : 0);
	else if (key == KEY_ENTER)
		param->guienabled = (param->guienabled == 0 ? 1 : 0);
	else if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_RETURN)
		param->cam.gradient = param->cam.gradient == 0 ? 1 : 0;
	else if (key == KEY_MINUS && param->cam.scale > 1)
		param->cam.scale--;
	else if (key == KEY_PLUS)
		param->cam.scale++;
	else if (key == KEY_LEFT)
		param->cam.xshift -= MOVE_SPEED;
	else if (key == KEY_RIGHT)
		param->cam.xshift += MOVE_SPEED;
	else if (key == KEY_UP)
		param->cam.yshift -= MOVE_SPEED;
	else if (key == KEY_DOWN)
		param->cam.yshift += MOVE_SPEED;
	draw_map(param);
	return (0);
}

int		main(int argc, char **argv)
{
	t_app app;

	if (argc != 2)
	{
		write(1, "Usage: fdf file\n", 16);
		return (0);
	}
	app = get_app(mlx_init());
	app.map = get_map(argv[1]);
	on_create(&app);
	mlx_hook(app.window, 2, 5, key_handler, &app);
	mlx_hook(app.window, 17, 1L << 17, close_click, &app);
	draw_map(&app);
	mlx_loop(app.mlx);
	return (0);
}
