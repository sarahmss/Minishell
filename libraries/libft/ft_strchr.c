/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:12:47 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/23 18:58:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*str_f;

	str_f = (char *)str;
	if (*str_f == '\0')
		return (NULL);
	if (!ft_isascii(c) && ft_isascii(*str_f))
		return (str_f);
	if (c == 0)
		return (str_f + ft_strlen(str));
	while (*str_f)
	{
		if (*str_f == c)
			return (str_f);
		if (!ft_isascii(*str_f))
			return (NULL);
		str_f++;
	}
	if (c == '\0' && *str_f == '\0')
		return (str_f);
	else
		return (NULL);
}
