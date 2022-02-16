# define function to be compiled
SRCS	=	ft_bzero.c		\
		ft_free_array.c		\
		ft_atoi.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memccpy.c		\
		ft_memmove.c		\
		ft_memset.c			\
		ft_memalloc.c		\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_str_replace.c	\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_tolower.c		\
		ft_strlen.c			\
		ft_calloc.c			\
		ft_itoa.c			\
		ft_substr.c			\
		ft_toupper.c		\
		ft_strjoin.c		\
		ft_strmapi.c		\
		ft_strtrim.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putnstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_strmapi.c		\
		ft_split.c			\
		ft_strcdup.c		\
		ft_putnbruns_fd.c	\
		ft_intlen.c			\
		ft_itoa_bases.c		\
		ft_strchr2.c		\
		ft_strnew.c			\
		ft_strncpy.c		\
		ft_atoi_base.c		\
		ft_max_mod_min.c	\
		ft_printf_simple.c	\
		get_next_line.c		\
		get_next_line_utils.c\
		ft_join_var.c		\


SRCS_B = ft_lstnew.c		\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c			\
		$(SRCS)
#.c.o
OBJ	=		$(SRCS:%.c=%.o)

OBJ_B =		$(SRCS_B:%.c=%.o)

NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -g

CC		=	gcc

all:		$(NAME)
#create libft with "ar" command and rcs flags(r- add member .o to file .a
#c- create libft.a if does no exists, s- make a indice)
$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)
			@ranlib $(NAME)

bonus: $(OBJ_B)
		@ar rcs $(NAME) $(OBJ_B)

#compile %.c -c flag to compile without main
%.o:		%.c
			@$(CC) -c $(CFLAGS) $< -o $@
clean:
			@rm -f $(OBJ)
			@rm -f $(OBJ_B)
fclean:		clean
			@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
