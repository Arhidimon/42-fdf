/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_rect_array.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:48:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/09 14:48:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_int_rect_array(t_vertex **array, int linesize)
{
	int i;

	while (*array)
	{
		i = 0;
		while (i < linesize)
		{
			ft_putnbr((*array)[i].vector[2]);
			ft_putstr(" ");
			i++;
		}
		ft_putchar('\n');
		(array)++;
	}
}
