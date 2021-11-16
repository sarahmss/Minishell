/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 22:15:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 10:38:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	static_ft_intlen(long numb)
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

static char	*static_ft_suport_itoa(int n, int i)
{
	char	*result;

	result = ft_calloc(sizeof(char), (i + 1));
	if (result == NULL)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	if (n == -2147483648)
		ft_strlcpy(result, "-2147483648", 12);
	if (n == 2147483647)
		ft_strlcpy(result, "2147483647", 11);
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	long	numb;
	char	*result;
	char	part;

	numb = n;
	i = static_ft_intlen(n);
	result = static_ft_suport_itoa(n, i);
	if (result == NULL)
		return (NULL);
	if (numb < 0 && n != 2147483647 && n != -2147483648)
	{
		result[0] = '-';
		numb = numb * -1;
	}
	while (numb > 0 && n != 2147483647 && n != -2147483648)
	{
		i--;
		part = numb % 10 + '0';
		result[i] = part;
		numb = numb / 10;
	}
	return (result);
}
