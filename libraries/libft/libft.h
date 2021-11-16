/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 10:07:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/15 20:53:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

//printf
typedef struct s_format
{
	va_list	args;
	char	*temp;
	int		printed;
}			t_format;

typedef struct s_positions
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		sign;
	char	*stemp;
}	t_positions;

typedef struct s_conversion
{
	int						i;
	long int				numb;
	char					*hex;
	char					*str;
}	t_conversion;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_strjoinchar(char *str, char c);

int		get_next_line(int fd, char **line);

void	ft_free_g(char **s_list);

int		ft_printf(const char *format, ...);

void	free_matrix(char **matrix);

void	*ft_memalloc(size_t size);

int		ft_atoi(const char *str);

int		ft_atoi_base(const char *str, int str_base);

void	ft_bzero(void *mem, size_t n_bytes);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

int		ft_isascii(int c);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *mem, int c, size_t n_bytes);

int		ft_memcmp(const void *mem1, const void *mem2, size_t n_bytes);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memset(void *mem, int const_byte, size_t n_bytes);

char	*ft_strchr(const char *str, int c);

char	*ft_strdup(const char *src);

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size);

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size);

int		ft_strlen(const char *str);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strnstr(const char *str, const char *to_find, size_t len);

char	*ft_strrchr(const char *str, int c);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_itoa(int n);

int		ft_tolower(int c);

int		ft_toupper(int c);

char	*ft_substr(char const *string, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

char	*ft_strtrim(char const *str, char const *set);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int		ft_putchar_fd(char c, int fd);

int		ft_putstr_fd(char *s, int fd);

int		ft_putnstr_fd(char *s, int fd, int n);

void	ft_putendl_fd(char *s, int fd);

int		ft_putnbr_fd(long n, int fd);

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

int		ft_lstsize(t_list *lst);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstclear(t_list **lst, void (*del)(void *));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));

char	*ft_strcdup(const char *src, char c);

int		ft_putnbruns_fd(unsigned int n, int fd);

int		ft_intlen(long numb);

int		ft_numblen(long numb, int base);

char	*ft_itoa_bases(long long int value, int base, char x);

char	*ft_strchr2(const char *str, int c, int c2);

void	free_array(void **matrix, int i);

float	mod(float a);

float	max(float a, float b);

float	min(float a, float b);

#endif
