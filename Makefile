# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#*   Updated: 2016/05/03 16:32:32 by jmarsal          ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fillit
INC_DIR = includes/
SRC_DIR = ./srcs/
SRC_FILES = main.c error.c block.c tetrimino.c resolve.c result.c \
		resolve_tools2.c map.c resolve_tools.c coords.c patterns.c
OBJ_FILES = $(SRC_FILES:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
ILIBFT = -Ilibft
LIBFT = -Llibft $(ILIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)

%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(ILIBFT)
clean:
	@make clean -C libft
	@rm -fv $(OBJ_FILES)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re

