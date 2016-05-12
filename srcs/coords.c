/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 14:32:37 by lsudre            #+#    #+#             */
/*   Updated: 2016/04/19 11:24:04 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_absolute_coords(t_block *cursor)
{
	t_block	*tmp;
	int		x_min;
	int		y_min;

	tmp = cursor;
	x_min = cursor->x;
	y_min = cursor->y;
	while (cursor)
	{
		if (x_min > cursor->x)
			x_min = cursor->x;
		if (y_min > cursor->y)
			y_min = cursor->y;
		cursor = cursor->next;
	}
	cursor = tmp;
	while (cursor)
	{
		cursor->x -= x_min;
		cursor->y -= y_min;
		cursor = cursor->next;
	}
}
