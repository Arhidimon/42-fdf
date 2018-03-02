/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 18:16:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/05 18:16:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "vector.h"

typedef struct	s_map
{
	t_vertex	**map;
	int			linesize;
	int			lines;
	int			minz;
	int			maxz;
}				t_map;

#endif
