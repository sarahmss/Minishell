# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/11 17:02:33 by smodesto          #+#    #+#              #
#    Updated: 2022/01/06 23:13:03 by smodesto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
LIBFT	= libft.a
READLINE = -lreadline -lncurses

LIBFT_PATH		= ./libraries/libft/
SRC_PATH		= ./source/
INCLUDES_PATH	= ./includes/
OBJS_PATH		= ./objects/

SRCS_FILES =	main/init_shell.c		\
				main/init_struct.c		\
				main/error_manager.c	\
				main/free.c				\
				main/repl.c				\
				main/greetings.c		\
				cmd_line/prompt.c		\
				cmd_line/sig_handler.c	\
				cmd_line/ft_read_line.c	\
				ht/ft_lstdoubly.c		\
				ht/ht_insert.c			\
				ht/ht_search.c			\
				ht/ht_delete.c			\
				ht/hash_table.c			\
				ht/ht_collisions.c		\
				token/tk_strtok.c		\
				token/tk_quotes1.c		\
				token/tk_quotes2.c		\
				token/tk_split_cmd.c	\
				token/tk_lst.c			\
				token/tk_pipe.c			\
				token/tk_root.c			\
				token/tk_error.c		\
				token/tk_make_one.c		\
				token/tk_insert_spaces.c\
				token/tk_create_tokens.c\
				token/tk_lexer.c		\
				env/env_load.c			\
				env/env_expansion.c		\
				env/env_variables.c		\
				env/env_local.c			\
				env/env_assign.c		\
				parse/parser_process.c	\
				parse/parser.c			\
				exec/exec_root.c		\
				exec/exec_path.c		\
				exec/exec_cmd.c			\
				builtins/builtins_root.c\
				builtins/echo.c			\
				builtins/exit.c			\
				builtins/env.c			\
				builtins/export.c		\
				builtins/unset.c		\
				builtins/pwd.c			\
				builtins/cd.c


SRCS = $(addprefix $(SRC_PATH), $(SRCS_FILES))

OBJS_FILES	= $(patsubst %.c, %.o, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

HEADER_FILES	=	Minishell.h		\
					token.h			\
					hash_table.h	\
					environment.h	\
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
			@mkdir -p objects
			@mkdir -p objects/ht
			@mkdir -p objects/main
			@mkdir -p objects/cmd_line
			@mkdir -p objects/token
			@mkdir -p objects/env
			@mkdir -p objects/parse
			@mkdir -p objects/builtins
			@mkdir -p objects/exec

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
