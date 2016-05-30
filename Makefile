# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmarsal <jmarsal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 00:34:02 by jmarsal           #+#    #+#              #
#    Updated: 2016/05/30 14:40:53 by jmarsal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
INC_DIR = ./includes/
INC_LIB = ./libft/includes
SRC_DIR = srcs/
SRC_FILES = main.c error.c block.c tetrimino.c resolve.c result.c \
		resolve_tools2.c resolve_tools.c patterns.c
OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_PATH)/%.o)
OBJ_PATH = ./obj
CC = gcc
CFLAGS = -Wall -Werror -Wextra
ILIBFT = -Ilibft/includes
LIBFT = -Llibft $(ILIBFT) -lft

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $^ -I$(INC_DIR) $(LIBFT)
	@echo "\n---------------------------------------------------------"
	@echo "|\033[32;1m\t\t$(NAME) has been created !\t\t\033[0m|"
	@echo "---------------------------------------------------------\n"

$(OBJ_PATH)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -o $@ -c $< $(ILIBFT)
clean:
	@make clean -C libft
	@rm -rf $(OBJ_PATH)
	@echo "\n-------------------------------------------------"
	@echo "|\t\033[31mall $(NAME) files.o are deleted\033[0m\t\t|"
	@echo "-------------------------------------------------\n"

fclean: clean
	@make fclean -C libft
	@rm -fv $(NAME)
	@echo "\n-----------------------------------------"
	@echo "|\t\033[31m$(NAME) is deleted\033[0m\t\t|"
	@echo "-----------------------------------------\n"

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

.PHONY:  all, clean, fclean, re
