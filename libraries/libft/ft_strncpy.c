/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:15:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/23 19:15:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	counter;
	char	*pointer_to_dest_start;
	size_t	src_len;

	pointer_to_dest_start = dst;
	src_len = ft_strlen(src);
	counter = 0;
	while (counter < len)
	{
		if (counter < src_len)
		{
			*dst = *src;
			src++;
		}
		else
			*dst = '\0';
		dst++;
		counter++;
	}
	return (pointer_to_dest_start);
}

char	*ft_strcpy(char *destination, const char *source)
{
	char	*ptr;

	if (destination == NULL)
		return (NULL);
	ptr = destination;
	while (*source != '\0')
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return (ptr);
}
