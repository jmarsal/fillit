/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 11:40:40 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/01 01:33:09 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_invalid_char_or_line(char c, int *x)
{
	if ((!(c == '.' || c == '#')) && *x < LINE_SIZE)
		return (-1);
	else if (c != '\n' && *x == LINE_SIZE)
		return (-1);
	if (c == '\n' && *x == LINE_SIZE)
		*x = 0;
	else
		*x += 1;
	return (0);
}

int		check_buffer_error(char *buffer, int *i, int *x)
{
	if (buffer[*i] == '\n' && buffer[*i + 1] == '\n')
		*i += 1;
	if (*i % 21 == MAP_SIZE && (!(buffer[*i] == '\n'
					|| buffer[*i] == '\0')))
		return (-1);
	else if (is_invalid_char_or_line(buffer[*i], x) == -1)
		return (-1);
	return (0);
}

int		can_build_list(t_app *app, t_pos *pos)
{
	while (app->buf[pos->i])
	{
		if (pos->i % 21 == 0)
			pos->tetrimino = create_tetrimino(NULL);
		if (pos->tetrimino == NULL)
			return (-1);
		if (check_buffer_error(app->buf, &pos->i, &pos->x) == -1)
			return (-1);
		if (app->buf[pos->i] == '#')
		{
			pos->block = create_block(pos->x, pos->y, app->count_tr + 'A');
			if (pos->block == NULL)
				return (-1);
			push_block_to_tetrimino(pos);
		}
		if (block_valid_push_tr(app, pos) == -1)
			return (-1);
		if (pos->x == 4)
			pos->y++;
		pos->i++;
	}
	return (0);
}
