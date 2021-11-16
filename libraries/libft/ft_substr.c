/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:46:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 21:12:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	char	*substr;
	int		i;

	i = 0;
	if (string == NULL)
		return (NULL);
	if ((int)start > ft_strlen(string))
	{
		substr = ft_calloc(sizeof(char), 1);
		if (!substr)
			return (NULL);
		return (substr);
	}
	if ((int)len > ft_strlen(string + start))
		substr = (char *)ft_calloc(sizeof(char), \
		(ft_strlen(string + start) + 1));
	else
		substr = ft_calloc(sizeof(char), (len + 1));
	if (substr == NULL)
		return (NULL);
	while (len-- >= 1)
		substr[i++] = string[start++];
	return (substr);
}
