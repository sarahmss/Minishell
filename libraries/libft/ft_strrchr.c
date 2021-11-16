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
