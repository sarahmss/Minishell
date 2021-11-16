/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:56:48 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/13 20:53:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(t_conversion *conv, long long int value, int base, char x)
{
	if (x == 'X')
		conv->hex = "0123456789ABCDEF";
	if (x == 'x')
		conv->hex = "0123456789abcdef";
	if (value < 0 && base == 10)
		conv->i = 2;
	else
		conv->i = 1;
	conv->numb = value;
	while (conv->numb / base)
	{
		conv->numb /= base;
		conv->i++;
	}
}

char	*ft_itoa_bases(long long int value, int base, char x)
{
	t_conversion	conv;

	if (value == 0)
		return (ft_strdup("0"));
	aux(&conv, value, base, x);
	conv.str = (char *)malloc(sizeof(char) * conv.i + 1);
	if (!conv.str)
		return (NULL);
	conv.str[conv.i] = 0;
	if (value < 0 && base == 10)
		conv.str[0] = '-';
	conv.numb = value;
	while (conv.numb)
	{
		if (conv.numb < 0)
			conv.numb *= -1;
		conv.str[--conv.i] = conv.hex[(conv.numb % base)];
		conv.numb /= base;
	}
	return (conv.str);
}
