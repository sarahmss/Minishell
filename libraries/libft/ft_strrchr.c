/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:12:47 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 19:22:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		str_len;
	char	*str_f;

	str_len = ft_strlen(str);
	str_f = (char *)str;
	if (!ft_isascii(c) && ft_isascii(*str_f))
		return (str_f);
	if ((char)c == '\0')
		return ((char *)(str_f + str_len));
	while (str_len--)
	{
		if (*(str_f + str_len) == c)
			return ((char *)(str_f + str_len));
		if (!ft_isascii(*(str_f + str_len)))
			return (NULL);
	}
	return (NULL);
}

/*
	1: char inside char
*/
int	c_in_c(char c, char *line)
{
	char	*c1;
	char	*c2;
	char	*temp;

	c1 = ft_strchr(line, c);
	if (c1 == NULL)
		return (0);
	c2 = ft_strchr(++c1, c);
	if (c2 == NULL)
		return (-1);
	temp = c2 + 1;
	if (*temp != '\0')
		return (c_in_c(c, temp));
	if (*(c2 + 1) == ' ' && *(c2 + 2) == c)
		return (0);
	else
		return (1);
}
