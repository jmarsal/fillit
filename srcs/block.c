/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 23:32:55 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/18 13:20:51 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block		*ft_create_block(int x, int y, char letter)
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

void		ft_push_block(t_block **blocks_list, t_block *block)
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

void		ft_blocks_clear(t_block **begin_list)
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
