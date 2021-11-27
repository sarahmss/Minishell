/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 11:37:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/15 20:34:27 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_g(const char *str, char n)
{
	int	len;

	len = 0;
	while (str[len] != n)
		len++;
	return (len);
}

char	*ft_strchr_g(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *) &s[i]);
}

char	*ft_strdup_g(const char *src, char c)
{
	char	*new_str;
	int		i;
	int		src_len;

	src_len = 0;
	while (src[src_len] != c)
		src_len++;
	new_str = malloc((sizeof (char)) * src_len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != c)
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	int			i;
	int			j;
	t_positions	pos;

	pos.len1 = ft_strlen_g((char *)s1, '\0');
	pos.len2 = ft_strlen_g((char *)s2, '\0');
	pos.len = pos.len1 + pos.len2;
	pos.stemp = malloc(sizeof(char) * (pos.len + 1));
	if (pos.stemp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < pos.len)
	{
		if (i < pos.len1)
			pos.stemp[i] = s1[i];
		else
		{
			pos.stemp[i] = s2[j];
			j++;
		}
		i++;
	}
	pos.stemp[i] = '\0';
	return (pos.stemp);
}

void	ft_free_g(char **s_list)
{
	if (*s_list != NULL)
	{
		free(*s_list);
		*s_list = NULL;
	}
}
