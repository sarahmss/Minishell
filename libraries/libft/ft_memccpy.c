/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 22:17:16 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 15:01:22 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c,
size_t n)
{
	size_t			pos;
	unsigned char	*mem_dest;
	unsigned char	*mem_src;

	mem_dest = (unsigned char *)dest;
	mem_src = (unsigned char *)src;
	pos = 0;
	while (pos < n)
	{
		mem_dest[pos] = mem_src[pos];
		if (mem_dest[pos] == (unsigned char)c)
			return ((void *) mem_dest + pos + 1);
		pos++;
	}
	return (NULL);
}
