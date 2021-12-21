/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:14:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/05/18 10:22:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *mem, size_t n_bytes)
{
	size_t			pos;
	unsigned char	*mem_f;

	pos = 0;
	mem_f = (unsigned char *)mem;
	while (pos < n_bytes)
	{
		mem_f[pos] = (unsigned char) '\0';
		pos++;
	}
}
