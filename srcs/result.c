/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:26:58 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/14 14:42:29 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_result		*ft_new_result(t_block *map, int max_width)
{
	t_result	*result;

	result = (t_result*)malloc(sizeof(t_result));
	if (result != NULL)
	{
		result->map = map;
		result->max_width = max_width;
	}
	else
	{
		free(result);
		return (NULL);
	}
	return (result);
}

t_tetrimino		*ft_cpy_tetrimino_list(t_tetrimino *tetriminos)
{
	t_tetrimino *cursor;
	t_tetrimino *ret;
	t_tetrimino *tmp;

	cursor = tetriminos;
	ret = NULL;
	while (cursor)
	{
		tmp = ft_create_tetrimino(NULL);
		tmp->blocks_list = ft_cpy_block_list(cursor->blocks_list);
		ft_push_tetrimino(&ret, tmp);
		cursor = cursor->next;
	}
	return (ret);
}

t_block			*ft_cpy_block_list(t_block *blocks_list)
{
	t_block *cursor;
	t_block *ret;
	t_block *tmp;

	cursor = blocks_list;
	ret = NULL;
	while (cursor)
	{
		if ((tmp = (t_block *)malloc(sizeof(t_block))) == NULL)
		{
			free(tmp);
			return (NULL);
		}
		tmp->x = cursor->x;
		tmp->y = cursor->y;
		tmp->letter = cursor->letter;
		tmp->next = NULL;
		ft_push_block(&ret, tmp);
		cursor = cursor->next;
	}
	return (ret);
}

t_tetrimino		*ft_del_tetrimino(t_tetrimino *tetriminos, char letter)
{
	t_tetrimino	*cursor;
	t_tetrimino	*prev;

	prev = NULL;
	cursor = tetriminos;
	while (cursor)
	{
		if (cursor->blocks_list->letter == letter)
		{
			if (prev)
				prev->next = cursor->next;
			else
				tetriminos = cursor->next;
			break ;
		}
		prev = cursor;
		cursor = cursor->next;
	}
	return (tetriminos);
}
