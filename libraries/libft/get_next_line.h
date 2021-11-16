/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:38:43 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/15 20:54:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/fcntl.h>

typedef struct s_positions
{
	char		*buffer;
	char		*stemp;
	int			len;
	int			len1;
	int			len2;
}	t_positions;

# define BUFFER_SIZE	1000

int		get_next_line(int fd, char **line);

char	*ft_strchr_g(const char *s, int c);

int		ft_strlen_g(const char *str, char n);

char	*ft_strdup_g(const char *src, char c);

char	*ft_strjoin_g(char const *s1, char const *s2);

void	ft_free_g(char **s_list);

#endif
