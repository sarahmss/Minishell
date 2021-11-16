/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 09:01:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 18:23:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	pos;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest > src)
	{
		while (len-- > 0)
		{
			((char *)dest)[len] = ((char *)src)[len];
		}
	}
	else
	{
		pos = 0;
		while (pos < len)
		{
			((char *)dest)[pos] = ((char *)src)[pos];
			pos++;
		}
	}
	return (dest);
}
