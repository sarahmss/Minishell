/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:35:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/28 09:44:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	cont;
	int	printed;

	cont = 0;
	while (s[cont] != '\0')
	{
		cont++;
	}
	printed = write(fd, s, cont);
	return (printed);
}
