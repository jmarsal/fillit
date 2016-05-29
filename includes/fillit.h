/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal  <jmarsal @student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:39:34 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/30 00:36:05 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFFER_SIZE 1024
# define MAP_SIZE 20
# define LINE_SIZE 4
# define PATTERNS_NB 19

# include "libft.h"
# include <fcntl.h>

typedef struct			s_patterns
{
	char				**tetri_patterns;
}						t_patterns;

typedef struct			s_block
{
	struct s_block		*next;
	int					x;
	int					y;
	char				letter;

}						t_block;

typedef struct			s_tetrimino
{
	struct s_tetrimino	*next;
	t_block				*blocks_list;
	int					nb_blocks;
}						t_tetrimino;

typedef struct			s_pos
{
	t_tetrimino			*tetrimino;
	t_block				*block;
	int					i;
	int					x;
	int					y;
}						t_pos;

typedef struct			s_helper_list
{
	t_tetrimino			*cursor;
	t_block				*block;
	t_block				*map;
	int					i;
	int					nb_match;
}						t_helper_list;

typedef struct			s_helper_result
{
	t_tetrimino			*cursor_tr;
	t_tetrimino			*valid_pos;
	t_tetrimino			*maj_cursor;
	t_block				*map_cpy;
}						t_helper_result;

typedef struct			s_result
{
	t_block				*map;
	int					max_width;
}						t_result;

typedef struct			s_app
{
	t_tetrimino			*tetri_list;
	t_patterns			patterns;
	t_result			*results;
	int					len;
	int					count_tr;
	int					max_width;
	int					complete_map;
	char				buf[BUFFER_SIZE];
}						t_app;


/*
 ** block.c
 */

t_block					*create_block(int x, int y, char letter);
void					push_block(t_block **blocks_list, t_block *block);
void					blocks_clear(t_block **begin_list);
t_block					*create_map(int max_width);
void					get_absolute_coords(t_block *cursor);

/*
 ** error.c
 */

int						is_invalid_char_or_line(char c, int *x);
int						check_buffer_error(char *buffer, int *i, int *x);
int						can_build_list(t_app *app, t_pos *pos);

/*
 ** patterns.c
 */

void					initialise_patterns(t_patterns *patterns);
char					convert_nb_to_char(int nb);
int						check_if_valid_tetrimino(char *pattern,
		t_block	*cur_blocks);
int						test_tetrimino_to_patterns(t_pos *posi,
				t_patterns patterns);

/*
 ** resolve_tools.c
 */

void					replace_x_of_tetrimino(t_block **tetrimino);
int						if_map_empty(t_block *map);
t_block					*check_pos(t_helper_list *real_pos,
 		t_helper_list *map_cpy, int *check, t_block *valid_pos);

t_block					*find_valid_pos(t_helper_list *map_cpy,
		t_block *valid_pos_bloc, t_helper_list *real_pos, t_block *map);

/*
 ** resolve_tools2.c
 */

t_tetrimino				*check_each_points(t_helper_list map_cpy,
 		t_helper_list real_pos, t_tetrimino *valid_pos, t_block *map);
t_tetrimino				*nb_match_in_map(t_tetrimino *cursor_tr,
 		t_block *map);
int						test_count(int count, t_block *map_cpy,
				t_block *cursor_coords, t_tetrimino valid_pos);
int						print_tetrimino_in_map(t_block *map,
				t_tetrimino valid_pos);

/*
 ** resolve.c
 */

void					while_incomplete(t_helper_result *resolve,
 		t_block *map, t_app *app, int max_width);
int						get_complete_map(t_app *app, t_block *map,
 		t_tetrimino *tetriminos, int max_width);
void					resolve(t_app *app);

/*
 ** result.c
 */

t_result				*new_result(t_block *map, int max_width);
t_tetrimino				*cpy_tetrimino_list(t_tetrimino *tetriminos);
t_block					*cpy_block_list(t_block *blocks);
t_tetrimino				*del_tetrimino(t_tetrimino *tetriminos, char letter);

/*
 ** tetrimino.c
 */

t_tetrimino				*create_tetrimino(t_block *blocks);
void					push_tetrimino(t_tetrimino **tetriminos,
 		t_tetrimino *tetrimino);
void					push_block_to_tetrimino(t_pos *pos);
int						block_valid_push_tr(t_app *app, t_pos *pos);










#endif
