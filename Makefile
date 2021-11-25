# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2021/11/25 18:15:32 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= Minishell
LIBFT	= libft.a
READLINE = -lreadline -lncurses

LIBFT_PATH		= ./libraries/libft/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main.c	\
				prompt.c \
				init.c 	\
				ft_lstdoubly.c	\
				hash_table_ut.c	\
				hash_table.c	\
				ht_collisions.c
				
SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	Minishell.h	\
					structs.h
HEADERS = $(addprefix $(INCLUDES_PATH), $(HEADER_FILES))

CC			= gcc
FLAGS		= -Wall -Wextra -g 
LIBRARIES	= -L$(LIBFT_PATH) -lft $(READLINE)
INCLUDES	= -I$(INCLUDES_PATH) -I$(LIBFT_PATH)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(OBJS) $(FLAGS) $(LIBRARIES) $(INCLUDES)  -o $(NAME)

$(OBJS_PATH)%.o : $(SRC_PATH)%.c $(HEADERS)
			$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
			@echo making libft...
			@echo --------------------------
			@make bonus -sC $(LIBFT_PATH)
			@echo done!
			@echo --------------------------

clean:
			@make -sC $(LIBFT_PATH) fclean
			@make -sC $(LIBFT_PATH) clean
			@rm -f $(OBJS)
			echo cleaned!
fclean:		clean
			@rm -f $(NAME)
re: fclean all

install:
	sudo apt-get install libreadline-dev

.PHONY: all clean fclean re
