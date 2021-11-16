/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:12:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 18:21:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocated_mem;

	allocated_mem = malloc((nmemb) * (size));
	if (allocated_mem == NULL)
		return (NULL);
	ft_bzero(allocated_mem, nmemb * size);
	return (allocated_mem);
}
