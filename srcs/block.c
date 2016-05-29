/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 23:32:55 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 00:34:34 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*create_block(int x, int y, char letter)
{
	t_block	*block;

	if ((block = (t_block*)malloc(sizeof(t_block))) == NULL)
		return (NULL);
	block->x = x;
	block->y = y;
	block->letter = letter;
	block->next = NULL;
	return (block);
}

void		push_block(t_block **blocks_list, t_block *block)
{
	t_block	*cursor;

	cursor = *blocks_list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = block;
	}
	else
		*blocks_list = block;
}

void		blocks_clear(t_block **begin_list)
{
	t_block	*tmp;
	t_block	*list;

	if (*begin_list)
	{
		tmp = *begin_list;
		while (tmp != NULL)
		{
			list = tmp->next;
			free(tmp);
			tmp = list;
		}
		*begin_list = NULL;
	}
}

t_block		*create_map(int max_width)
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
		push_block(&map, create_block(x, y, '.'));
		x++;
	}
	return (map);
}

void	get_absolute_coords(t_block *cursor)
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
