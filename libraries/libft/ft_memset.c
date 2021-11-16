/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:11:29 by smodesto          #+#    #+#             */
/*   Updated: 2021/05/16 20:36:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int const_byte, size_t n_bytes)
{
	size_t			pos;
	unsigned char	*mem_f;

	pos = 0;
	mem_f = (unsigned char *)mem;
	while (pos < n_bytes)
		mem_f[pos++] = (unsigned char)const_byte;
	return (mem);
}
