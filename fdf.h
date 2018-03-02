/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:48:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 17:48:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WINDOW_W 1600
# define WINDOW_H 1200

# define SKIN "fdfskin.xpm"
# define SKINHELP "fdfskinhelp.xpm"

# define PI 3.14159265359
# define MOVE_SPEED 15
# define ROTATION_SPEED PI/36

# define A_X a.vector[0]
# define A_Y a.vector[1]
# define B_X b.vector[0]
# define B_Y b.vector[1]

# define MULTIPLIER 25
# define ABS(N) (N < 0 ? -(N) : N)

# include "minilibx/mlx.h"
# include "point.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include "map.h"
# include "vector.h"

typedef struct			s_cam
{
	double			a;
	double			b;
	double			g;
	int				xshift;
	int				yshift;
	int				zshift;
	int				scale;
	int				focus;
	unsigned int	gradient;
	double			matrix[16];
}						t_cam;

typedef struct			s_app
{
	void				*mlx;
	void				*window;
	void				*gui;
	void				*guihelp;
	void				*image;
	t_map				*map;
	t_map				*transformed;
	t_cam				cam;
	int					nogui;
	int					guienabled;
	int					helpenabled;
}						t_app;

int						rgb_to_int(unsigned char red, unsigned char green,
						unsigned char blue);
void					draw_menu(t_app *app);
void					img_pixel_plot(void *image, t_point a, int color);
t_point					get_point(int x, int y);
t_app					get_app(void *mlx);
t_map					*get_map(char *filename);
void					add_to_map(t_vertex ***array, t_vertex *row);
void					print_int_rect_array(t_vertex**array, int linesize);
void					draw_map(t_app *app);
t_point					vector_to_point(t_app *app, t_vector vector);
void					render(t_app *app);
void					on_create(t_app *app);
t_vector				rotate(t_app *app, t_vector vector);
t_vector				transform(t_app *app, t_vector vector);
void					seppuku(int code, char *lastworld);

t_vertex				parsevertex(char **str);
void					free_map(t_map *map);
void					img_draw_line(t_app *app, t_vertex a, t_vertex b);
#endif
