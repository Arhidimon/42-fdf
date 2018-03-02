/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:07:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 19:07:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "point.h"

t_point	get_point(int x, int y)
{
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}
