/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 23:18:54 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/14 17:09:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_positions	pos;
	int			len;

	pos.k = ft_strlen((char *)s1);
	len = ((int)pos.k + ft_strlen((char *)s2));
	pos.stemp = malloc(sizeof(char) * (len + 1));
	if (pos.stemp == NULL)
		return (NULL);
	pos.i = 0;
	pos.j = 0;
	while ((int)pos.i < len)
	{
		if (pos.i < pos.k)
			pos.stemp[pos.i] = s1[pos.i];
		else
		{
			pos.stemp[pos.i] = s2[pos.j];
			pos.j++;
		}
		pos.i++;
	}
	pos.stemp[pos.i] = '\0';
	return (pos.stemp);
}

char	*ft_strjoinchar(char *str, char c)
{
	char	*strf;
	int		i;

	i = 0;
	strf = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 3);
	strf[0] = c;
	while (i < ft_strlen(str))
	{
		strf[i + 1] = str[i];
		i++;
	}
	strf[i + 1] = c;
	return (strf);
}
