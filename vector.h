/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:58:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/02/12 18:58:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef float	t_vector __attribute__((vector_size(sizeof(float)*4)));

typedef struct	s_vertex
{
	t_vector	vector;
	int			color;
}				t_vertex;

#endif
