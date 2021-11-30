/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 18:08:34 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/28 09:15:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long numb)
{
	int	len;

	len = 0;
	if (numb == 0)
		return (1);
	if (numb < 0)
	{
		numb = numb * -1;
		len++;
	}
	while (numb > 0)
	{
		numb = numb / 10;
		len++;
	}
	return (len);
}

int	ft_numblen(long numb, int base)
{
	int	len;

	len = 0;
	if (numb == 0)
		return (1);
	if (numb < 0)
	{
		numb = numb * -1;
		len++;
	}
	while (numb > 0)
	{
		numb = numb / base;
		len++;
	}
	return (len);
}

int	ft_arraylen(void **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}
