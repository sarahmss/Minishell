/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 10:10:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/05/27 10:04:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem, int c, size_t n_bytes)
{
	unsigned char	*mem_f;
	unsigned int	ch;

	ch = (unsigned char)c;
	mem_f = (unsigned char *)mem;
	while (n_bytes--)
	{
		if (*mem_f == ch)
			return (mem_f);
		mem_f++;
	}
	return (NULL);
}
