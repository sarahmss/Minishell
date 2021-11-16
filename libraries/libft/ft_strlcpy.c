/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:38:15 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 15:02:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dest_size)
{
	size_t	i;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	if (dest_size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < (dest_size - 1) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (i < dest_size)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
