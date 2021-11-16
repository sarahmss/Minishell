/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:10:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 15:01:43 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src,
size_t size)
{
	size_t		src_len;
	size_t		dest_len;
	t_positions	pos;
	char		*srcp;

	pos.i = 0;
	pos.j = 0;
	srcp = (char *)src;
	dest_len = ft_strlen((char *)dest);
	src_len = ft_strlen((char *)src);
	if (size > dest_len)
		pos.j = dest_len + src_len;
	else
		pos.j = src_len + size;
	while (src[pos.i] && (dest_len + 1) < size)
	{
		dest[dest_len] = srcp[pos.i];
		dest_len++;
		pos.i++;
	}
	if (dest_len < size)
		dest[dest_len] = '\0';
	return (pos.j);
}
