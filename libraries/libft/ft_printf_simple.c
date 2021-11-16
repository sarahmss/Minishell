/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_simple.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:23:05 by smodesto          #+#    #+#             */
/*   Updated: 2021/08/23 18:59:31 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_eval_format(char *temp, t_format *tab)
{
	tab->temp = temp;
	temp++;
	if (*temp == 's')
		tab->printed += ft_putstr_fd(va_arg(tab->args, char *), 1);
	if (*temp == 'c')
		tab->printed += ft_putchar_fd(va_arg(tab->args, int), 1);
	if (*temp == '%')
		tab->printed += ft_putchar_fd('%', 1);
	if ((*temp == 'i') || (*temp == 'd'))
		tab->printed += ft_putnbr_fd(va_arg(tab->args, int), 1);
	if (*temp == 'u')
		tab->printed += ft_putnbruns_fd(va_arg(tab->args, unsigned int), 1);
	temp++;
	tab->temp = temp;
	if (*temp == '\0')
		tab->temp = NULL;
	return (temp);
}

static int	ft_main_printf(char *str, t_format *tab)
{
	char		*temp;

	temp = NULL;
	if (str == NULL)
		return (tab->printed);
	if (!ft_strchr(str, '%'))
	{
		tab->printed += ft_putstr_fd(str, 1);
		return (tab->printed);
	}
	temp = ft_strcdup(str, '%');
	if (!temp)
		return (-1);
	tab->printed += ft_putstr_fd(temp, 1);
	free (temp);
	temp = ft_strchr(str, '%');
	temp = ft_eval_format(temp, tab);
	return (ft_main_printf(temp, tab));
}

int	ft_printf(const char *format, ...)
{
	t_format	*tab;
	int			printed;

	tab = (t_format *)malloc(sizeof(t_format));
	if (!tab)
		return (-1);
	tab->temp = NULL;
	tab->printed = 0;
	va_start(tab->args, format);
	printed = ft_main_printf((char *)format, tab);
	free(tab);
	return (printed);
}
