/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:47:31 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 10:47:32 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		replace_x_of_tetrimino(t_block **tetrimino)
{
	t_block	*cursor;

	cursor = *tetrimino;
	while (cursor)
	{
		cursor->x -= 1;
		cursor = cursor->next;
	}
}

int			if_map_empty(t_block *map)
{
	t_block	*cursor;
	int		test;

	test = 0;
	cursor = map;
	while (cursor)
	{
		if (cursor->letter != '.')
			test = -1;
		cursor = cursor->next;
	}
	return (test);
}

t_block		*check_pos(t_helper_list *real_pos, t_helper_list *map_cpy,
		int *check, t_block *valid_pos)
{
	if (real_pos->map->x == map_cpy->map->x + real_pos->block->x &&
			real_pos->map->y == map_cpy->map->y + real_pos->block->y &&
			real_pos->map->letter == '.')
	{
		map_cpy->nb_match += 1;
		*check += 1;
		push_block(&valid_pos, create_block(real_pos->map->x,
					real_pos->map->y, real_pos->block->letter));
		real_pos->block = real_pos->block->next;
	}
	return (valid_pos);
}

t_block		*find_valid_pos(t_helper_list *map_cpy, t_block *valid_pos_block,
		t_helper_list *real_pos, t_block *map)
{
	t_block	*valid_pos;
	int		check;
	int		map_empty;

	valid_pos = NULL;
	check = 0;
	map_empty = if_map_empty(map);
	while (real_pos->map && real_pos->block && map_cpy->nb_match <= 4)
	{
		if (map_empty == -1 && real_pos->block->x == 1 && check == 0)
			replace_x_of_tetrimino(&real_pos->block);
		if (map_empty == 0 && real_pos->block->x == 1 && check == 0)
			real_pos->block = map_cpy->block;
		if (map_empty == 0 && real_pos->block->x == 2 && check == 0)
			replace_x_of_tetrimino(&real_pos->block);
		valid_pos = check_pos(real_pos, map_cpy, &check, valid_pos);
		if (map_cpy->nb_match == 4)
		{
			real_pos->block = map_cpy->block;
			return (valid_pos);
		}
		real_pos->map = real_pos->map->next;
	}
	return (valid_pos_block = NULL);
}
