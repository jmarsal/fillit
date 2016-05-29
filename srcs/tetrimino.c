/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 22:31:18 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 00:15:07 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*create_tetrimino(t_block *blocks_list)
{
	t_tetrimino *tetrimino;

	if ((tetrimino = (t_tetrimino *)malloc(sizeof(t_tetrimino))) == NULL)
		return (NULL);
	tetrimino->blocks_list = blocks_list;
	tetrimino->nb_blocks = 0;
	tetrimino->next = NULL;
	return (tetrimino);
}

void			push_tetrimino(t_tetrimino **tetri_list,
									t_tetrimino *tetrimino)
{
	t_tetrimino	*cursor;

	cursor = *tetri_list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = tetrimino;
	}
	else
		*tetri_list = tetrimino;
}

void			push_block_to_tetrimino(t_pos *pos)
{
	t_block	*cursor;

	cursor = pos->tetrimino->blocks_list;
	if (cursor)
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = pos->block;
	}
	else
		pos->tetrimino->blocks_list = pos->block;
	pos->tetrimino->nb_blocks++;
}

int				block_valid_push_tr(t_app *app, t_pos *pos)
{
	if (pos->i % 21 == MAP_SIZE || app->buf[pos->i + 1] == '\0')
	{
		if (pos->tetrimino->nb_blocks == 4)
		{
			get_absolute_coords(pos->tetrimino->blocks_list);
			if (test_tetrimino_to_patterns(pos, app->patterns)
											== -1)
				return (-1);
			push_tetrimino(&app->tetri_list, pos->tetrimino);
			app->count_tr++;
		}
		else
			return (-1);
	}
	return (0);
}
