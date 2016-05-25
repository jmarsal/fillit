/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:39:34 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/25 15:22:47 by jmarsal          ###   ########.fr       */
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

void					print_map(t_block **map, int max_width);
void					ft_push_block(t_block **blocks_list, t_block *block);
void					ft_blocks_clear(t_block **begin_list);
t_block					*ft_create_block(int x, int y, char letter);
void					ft_get_absolute_coords(t_block *cursor);
int						ft_is_invalid_char_or_line(char c, int *x);
int						ft_check_buffer_error(char *buffer, int *i, int *x);
int						ft_test_block_touch(t_pos *pos);
int						ft_can_build_list(t_app *app, t_pos *pos);
t_block					*ft_create_map(int max_width);
void					ft_put_points_to_map(t_helper_result *helper,
		int max_width);
void					ft_while_incomplete(t_helper_result *resolve,
		t_block *map, t_app *app, int max_width);
int						ft_get_complete_map(t_app *app, t_block *map,
		t_tetrimino *tetriminos, int max_width);
void					ft_resolve(t_app *app);
void					ft_replace_x_of_tetrimino(t_block **tetrimino);
int						ft_if_map_empty(t_block *map);
t_block					*ft_check_pos(t_helper_list *real_pos,
		t_helper_list *map_cpy, int *check, t_block *valid_pos);
t_block					*ft_valid_pos(t_helper_list *map_cpy,
		t_block *valid_pos_bloc, t_helper_list *real_pos, t_block *map);
t_tetrimino				*ft_check_each_points(t_helper_list map_cpy,
		t_helper_list real_pos, t_tetrimino *valid_pos, t_block *map);
t_tetrimino				*ft_nb_match_in_map(t_tetrimino *cursor_tr,
		t_block *map);
int						ft_test_count(int count, t_block *map_cpy,
		t_block *cursor_coords, t_tetrimino valid_pos);
int						ft_print_tetrimino_in_map(t_block *map,
		t_tetrimino valid_pos);
t_result				*ft_new_result(t_block *map, int max_width);
t_tetrimino				*ft_cpy_tetrimino_list(t_tetrimino *tetriminos);
t_block					*ft_cpy_block_list(t_block *blocks);
t_tetrimino				*ft_del_tetrimino(t_tetrimino *tetriminos, char letter);
t_tetrimino				*ft_create_tetrimino(t_block *blocks);
void					ft_push_tetrimino(t_tetrimino **tetriminos,
		t_tetrimino *tetrimino);
void					ft_push_block_to_tetrimino(t_pos *pos);
int						ft_block_valid_push_tr(t_app *app, t_pos *pos);
void					initialise_patterns(t_patterns *patterns);
int						test_tetrimino_to_patterns(t_pos *posi,
		t_patterns patterns);
char					convert_nb_to_char(int nb);
int						check_if_valid_tetrimino(char *pattern,
		t_block	*cur_blocks);

#endif
