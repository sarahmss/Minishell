/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 22:17:16 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 18:23:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			pos;
	char			*mem_dest;
	const char		*mem_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	pos = 0;
	mem_dest = (char *)dest;
	mem_src = (const char *)src;
	while (pos < n)
	{
		mem_dest[pos] = mem_src[pos];
		pos++;
	}
	return ((void *)mem_dest);
}
