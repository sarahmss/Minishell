/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 19:41:05 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 20:29:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	free_array(void **matrix, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
