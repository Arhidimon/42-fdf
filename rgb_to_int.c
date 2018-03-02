/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbezruch <dbezruch@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:52:00 by dbezruch          #+#    #+#             */
/*   Updated: 2018/01/31 17:52:00 by dbezruch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		rgb_to_int(unsigned char red, unsigned char green, unsigned char blue)
{
	return (((red << 16) | (green << 8) | blue));
}
