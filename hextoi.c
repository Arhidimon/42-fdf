/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hextoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:52:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/20 18:52:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	chartoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'W');
	if (c >= 'A' && c <= 'F')
		return (c - '7');
	return (0);
}

int				hextoi(char **str)
{
	int		n;
	char	*s;

	s = *str;
	n = 0;
	while ((*s >= '0' && *s <= '9') || (*s >= 'a' && *s <= 'f') ||
			(*s >= 'A' && *s <= 'F'))
	{
		n = n * 16 + (chartoi(*s));
		s++;
	}
	*str = s;
	return (n);
}

int				atoi_skip(char **str)
{
	unsigned long int	n;
	int					sign;
	char				*s;

	s = *str;
	n = 0;
	sign = 1;
	while (ft_is_whitespace(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	*str = s;
	return ((int)(sign * n));
}

t_vertex		parsevertex(char **str)
{
	char				*s;
	t_vertex			vert;

	vert.vector = (t_vector){0, 0, atoi_skip(str)};
	s = *str;
	if (s[0] == ',' && s[1] == '0' && s[2] == 'x')
	{
		s += 3;
		vert.color = hextoi(&s);
	}
	else
		vert.color = 0x0000AAAA;
	if (*s)
		*str = s + 1;
	else
		*str = s;
	return (vert);
}
