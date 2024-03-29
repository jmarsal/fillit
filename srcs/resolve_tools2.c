/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_tools2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 10:47:47 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 10:47:48 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetrimino		*check_each_points(t_helper_list map_cpy,
		t_helper_list real_pos, t_tetrimino *valid_pos, t_block *map)
{
	t_block			*valid_block;

	valid_block = NULL;
	while (map_cpy.map)
	{
		if (map_cpy.map->letter == '.')
		{
			real_pos.map = map_cpy.map;
			valid_block = find_valid_pos(&map_cpy, valid_block, &real_pos, map);
		}
		if (map_cpy.nb_match == 4)
		{
			map_cpy.nb_match = 0;
			push_tetrimino(&valid_pos, create_tetrimino(valid_block));
			valid_block = NULL;
		}
		else
		{
			blocks_clear(&valid_block);
			real_pos.block = map_cpy.block;
			map_cpy.nb_match = 0;
		}
		map_cpy.map = map_cpy.map->next;
	}
	return (valid_pos);
}

t_tetrimino		*nb_match_in_map(t_tetrimino *cursor_tr, t_block *map)
{
	t_helper_list	map_cpy;
	t_helper_list	real_pos;
	t_tetrimino		*valid_pos;

	map_cpy.nb_match = 0;
	map_cpy.cursor = cursor_tr;
	valid_pos = NULL;
	real_pos.i = 0;
	while (map_cpy.cursor)
	{
		map_cpy.map = cpy_block_list(map);
		real_pos.block = map_cpy.cursor->blocks_list;
		map_cpy.block = map_cpy.cursor->blocks_list;
		valid_pos = check_each_points(map_cpy, real_pos, valid_pos, map);
		map_cpy.cursor = map_cpy.cursor->next;
	}
	return (valid_pos);
}

int				test_count(int count, t_block *map_cpy,
							t_block *cursor_coords, t_tetrimino valid_pos)
{
	if (count == 4)
	{
		while (map_cpy && cursor_coords)
		{
			if (map_cpy->x == cursor_coords->x &&
					map_cpy->y == cursor_coords->y)
			{
				map_cpy->letter = valid_pos.blocks_list->letter;
				cursor_coords = cursor_coords->next;
			}
			map_cpy = map_cpy->next;
		}
		return (0);
	}
	return (1);
}

int				print_tetrimino_in_map(t_block *map, t_tetrimino valid_pos)
{
	t_block	*map_cpy;
	t_block	*cursor_map;
	t_block	*cursor_coords;
	int		count;

	cursor_map = map;
	cursor_coords = valid_pos.blocks_list;
	map_cpy = map;
	count = 0;
	while (cursor_map && cursor_coords)
	{
		if (cursor_map->x == cursor_coords->x &&
				cursor_map->y == cursor_coords->y)
		{
			count++;
			cursor_coords = cursor_coords->next;
		}
		cursor_map = cursor_map->next;
	}
	cursor_coords = valid_pos.blocks_list;
	if (test_count(count, map_cpy, cursor_coords, valid_pos) == 0)
		return (0);
	return (-1);
}
