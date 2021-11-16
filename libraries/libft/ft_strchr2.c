/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:12:47 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/09 16:20:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr2(const char *str, int c, int c2)
{
	char	*str_f;

	str_f = (char *)str;
	if (!ft_isascii(c) && ft_isascii(*str_f))
		return (str_f);
	if (c == 0)
		return (str_f + ft_strlen(str));
	while (*str_f)
	{
		if (*str_f == c)
		{
			str_f++;
			if (*str_f == c2)
				return (str_f);
		}
		if (!ft_isascii(*str_f))
			return (NULL);
	}
	if (c == '\0' && *str_f == '\0')
		return (str_f);
	else
		return (NULL);
}
