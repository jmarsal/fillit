/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 10:52:03 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 00:10:55 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_block **map, int max_width)
{
	t_block		*cursor;
	int			count;
	int			backline;

	backline = max_width;
	count = 0;
	cursor = *map;
	while (cursor)
	{
		if (count == backline)
		{
			ft_putchar('\n');
			count = 0;
		}
		ft_putchar(cursor->letter);
		count++;
		cursor = cursor->next;
	}
	ft_putchar('\n');
}

int		read_file(char **av, t_app *app)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	app->len = (int)read(fd, app->buf, BUFFER_SIZE);
	if (close(fd) == -1 || app->len <= 0 || (app->len + 1) % 21 != 0)
		return (-1);
	app->buf[app->len] = '\0';
	return (0);
}

int		fillit(t_app *app)
{
	t_pos pos;

	pos.i = 0;
	pos.x = 0;
	pos.y = 0;
	app->patterns.tetri_patterns = (char**)malloc(sizeof(char*) * PATTERNS_NB);
	initialise_patterns(&app->patterns);
	if (can_build_list(app, &pos) == 0)
	{
		resolve(app);
		if (app->results)
			print_map(&app->results->map, app->results->max_width);
		return (0);
	}
	else
		free(app->results);
	return (-1);
}

int		main(int ac, char **av)
{
	t_app app;

	app.tetri_list = NULL;
	app.count_tr = 0;
	app.results = NULL;
	app.max_width = 0;
	if (ac == 2)
	{
		if (read_file(av, &app) == -1 || fillit(&app) == -1)
		{
			ft_putstr("error\n");
			return (-1);
		}
	}
	else
	{
		ft_putstr("usage: ./fillit source_file\n");
		return (-1);
	}
	return (0);
}
