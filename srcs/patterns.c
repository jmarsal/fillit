/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 22:35:07 by jmarsal           #+#    #+#             */
/*   Updated: 2016/05/02 13:21:00 by jmarsal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		initialise_patterns(t_patterns *patterns)
{
	patterns->tetri_patterns[0] = "00100111";
	patterns->tetri_patterns[1] = "00011102";
	patterns->tetri_patterns[2] = "00102011";
	patterns->tetri_patterns[3] = "10011112";
	patterns->tetri_patterns[4] = "10011121";
	patterns->tetri_patterns[5] = "00010203";
	patterns->tetri_patterns[6] = "00102030";
	patterns->tetri_patterns[7] = "00100102";
	patterns->tetri_patterns[8] = "00102021";
	patterns->tetri_patterns[9] = "10110212";
	patterns->tetri_patterns[10] = "00011121";
	patterns->tetri_patterns[11] = "00101112";
	patterns->tetri_patterns[12] = "20011121";
	patterns->tetri_patterns[13] = "00010212";
	patterns->tetri_patterns[14] = "00102001";
	patterns->tetri_patterns[15] = "00101121";
	patterns->tetri_patterns[16] = "10011102";
	patterns->tetri_patterns[17] = "10200111";
	patterns->tetri_patterns[18] = "00011112";
}

char		convert_nb_to_char(int nb)
{
	return (nb + '0');
}

int			check_if_valid_tetrimino(char *pattern, t_block *cur_blocks)
{
	int		j;

	j = 0;
	while (pattern[j] && cur_blocks)
	{
		if (convert_nb_to_char(cur_blocks->x) == pattern[j])
			j++;
		else
			return (-1);
		if (convert_nb_to_char(cur_blocks->y) == pattern[j])
			j++;
		else
			return (-1);
		cur_blocks = cur_blocks->next;
	}
	return (0);
}

int			test_tetrimino_to_patterns(t_pos *pos, t_patterns patterns)
{
	t_block		*cur_blocks;
	int			i;
	int			j;

	i = 0;
	while (i < PATTERNS_NB)
	{
		cur_blocks = pos->tetrimino->blocks_list;
		j = 0;
		if (check_if_valid_tetrimino(patterns.tetri_patterns[i], cur_blocks)
				== 0)
			return (i);
		else
			i++;
	}
	return (-1);
}
