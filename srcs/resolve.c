/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 01:31:04 by jmarsal           #+#    #+#             */
/*   Updated: 2016/04/18 13:37:23 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	while_incomplete(t_helper_result *resolve, t_block *map, t_app *app,
		int max_width)
{
	while (app->complete_map == -1 && resolve->valid_pos)
	{
		resolve->map_cpy = cpy_block_list(map);
		if ((print_tetrimino_in_map(resolve->map_cpy,
						*resolve->valid_pos)) == 0)
		{
			resolve->maj_cursor = cpy_tetrimino_list(resolve->cursor_tr);
			resolve->maj_cursor = del_tetrimino(resolve->maj_cursor,
					resolve->valid_pos->blocks_list->letter);
			app->complete_map = get_complete_map(app, resolve->map_cpy,
					resolve->maj_cursor, max_width);
		}
		resolve->valid_pos = resolve->valid_pos->next;
	}
}

int		get_complete_map(t_app *app, t_block *map, t_tetrimino *tetriminos,
		int max_width)
{
	t_helper_result resolve;

	resolve.cursor_tr = tetriminos;
	resolve.valid_pos = nb_match_in_map(resolve.cursor_tr, map);
	while_incomplete(&resolve, map, app, max_width);
	if (app->complete_map == 0 && resolve.maj_cursor == NULL)
	{
		app->results = new_result(resolve.map_cpy, app->max_width);
		return (0);
	}
	return ((resolve.cursor_tr != NULL && resolve.valid_pos == NULL) ? -1 : 0);
}

void	resolve(t_app *app)
{
	t_tetrimino	*tetri_cpy;
	t_block		*map;

	app->complete_map = -1;
	app->max_width = 0;
	while (app->max_width * app->max_width < (app->count_tr * 4))
		app->max_width += 1;
	while (app->complete_map == -1)
	{
		tetri_cpy = cpy_tetrimino_list(app->tetri_list);
		map = create_map(app->max_width);
		if ((app->complete_map = get_complete_map(app, map, tetri_cpy,
						app->max_width)) == -1)
			app->max_width += 1;
	}
}
