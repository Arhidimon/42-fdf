/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:19:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/05 18:19:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "fdf.h"

void	add_to_map(t_vertex ***array, t_vertex *row)
{
	int			i;
	t_vertex	**newarray;

	i = 0;
	if (*array)
	{
		while ((*array)[i])
			i++;
	}
	newarray = (t_vertex**)malloc(sizeof(t_vertex*) * (i + 2));
	if (*array)
	{
		i = -1;
		while ((*array)[++i])
			newarray[i] = (*array)[i];
		free(*array);
	}
	newarray[i] = row;
	newarray[i + 1] = NULL;
	*array = newarray;
}

void	free_map(t_map *map)
{
	int i;

	if (!map)
		return ;
	i = 0;
	while (i < map->lines)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map);
}
