/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:17:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 14:08:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_var(unsigned int arg_quantity, ...)
{
	va_list			arg_list;
	unsigned int	i;
	char			*arg_buffer;
	char			*temp;
	char			*result;

	va_start(arg_list, arg_quantity);
	i = 0;
	result = NULL;
	while (i < arg_quantity)
	{
		arg_buffer = va_arg(arg_list, char *);
		if (result == NULL)
			result = ft_strdup(arg_buffer);
		else
		{
			temp = ft_strjoin(result, arg_buffer);
			free(result);
			result = temp;
		}
		i++;
	}
	va_end(arg_list);
	return (result);
}
