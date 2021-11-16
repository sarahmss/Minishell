/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:41:57 by smomem1o          #+#    #+#             */
/*   Updated: 2021/05/27 09:39:27 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t n_bytes)
{
	const unsigned char	*_mem1;
	const unsigned char	*_mem2;

	_mem1 = (const unsigned char *)mem1;
	_mem2 = (const unsigned char *)mem2;
	if (n_bytes <= 0 || mem1 == mem2)
		return (0);
	while (n_bytes--)
	{
		if (*_mem1 != *_mem2)
			return (*_mem1 - *_mem2);
		if (n_bytes)
		{
			_mem1++;
			_mem2++;
		}
	}
	return (0);
}
