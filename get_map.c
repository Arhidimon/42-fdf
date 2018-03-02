/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:07:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/05 16:07:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

int		map_count_width(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			i++;
			while (*str >= '0' && *str <= '9')
				str++;
		}
		else
			str++;
		if (str[0] == ',' && str[1] == '0' && str[2] == 'x')
		{
			str += 3;
			while ((*str >= '0' && *str <= '9') || (*str >= 'a' && *str <= 'f')
					|| (*str >= 'A' && *str <= 'F'))
				str++;
		}
	}
	return (i);
}

void	parseline(char *str, int line, int size, t_map *map)
{
	int			i;
	t_vertex	*row;

	row = (t_vertex*)malloc(sizeof(t_vertex) * size);
	i = 0;
	while (*str)
	{
		row[i] = parsevertex(&str);
		map->minz = map->minz > row[i].vector[2] ? row[i].vector[2] : map->minz;
		map->maxz = map->maxz < row[i].vector[2] ? row[i].vector[2] : map->maxz;
		row[i].vector[0] = i - size / 2;
		row[i].vector[1] = line;
		i++;
	}
	add_to_map(&(map->map), row);
}

int		parsemap(int fd, t_map *map)
{
	char	*str;
	int		width;
	int		newwidth;
	int		line;

	line = 0;
	if (get_next_line(fd, &str) == 1)
	{
		width = map_count_width(str);
		parseline(str, line, width, map);
		line++;
		free(str);
		while (get_next_line(fd, &str) == 1)
		{
			newwidth = map_count_width(str);
			if (newwidth != width)
				seppuku(0, "fdf wrong map!");
			parseline(str, line, width, map);
			line++;
			free(str);
		}
		map->linesize = width;
	}
	map->lines = line;
	return (0);
}

t_map	*get_map(char *filename)
{
	int		file;
	t_map	*map;

	if ((file = open(filename, O_RDONLY)) <= -1)
		seppuku(1, "fdf");
	map = malloc(sizeof(t_map));
	map->map = NULL;
	map->minz = 0;
	map->maxz = 0;
	parsemap(file, map);
	if (map->lines == 0)
		seppuku(1, "fdf");
	return (map);
}
