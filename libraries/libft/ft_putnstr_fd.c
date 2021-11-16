/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:17:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/07/09 10:57:32 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(char *s, int fd, int n)
{
	int	cont;
	int	printed;

	cont = 0;
	printed = 0;
	if (n == -1)
		return (printed);
	if (n > 0)
		while (s[cont] != '\0' && n-- > 0)
			cont++;
	else
		while (s[cont] != '\0')
			cont++;
	printed = write(fd, s, cont);
	return (printed);
}
