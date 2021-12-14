/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 19:06:18 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/09 16:22:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122) || (48 <= c && c <= 57))
		return (1);
	else
		return (0);
}
/*
int	ft_strisalnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && (48 <= str[i + 1] && str[i + 1] <= 57))
			ft_strisalnum(&str[i + 1]);
		else if (!(48 <= str[i] && str[i] <= 57) || (i > 10)
			|| ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
			return (0);
		i++;
	}
	return (1);
}
*/
