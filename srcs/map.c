/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 16:23:53 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/26 00:12:08 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*ft_create_map(int max_width)
{
	t_block	*map;
	int		count;
	int		x;
	int		y;

	map = NULL;
	count = 0;
	x = 0;
	y = 0;
	while (count++ < (max_width * max_width))
	{
		if (x == max_width)
		{
			x = 0;
			y++;
		}
		ft_push_block(&map, ft_create_block(x, y, '.'));
		x++;
	}
	return (map);
}
