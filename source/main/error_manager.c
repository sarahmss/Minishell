/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:35:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 20:35:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	errmsg(char *str)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
}

void	ft_check_error(t_errcode code, char *msg, t_cmd_tab *table)
{
	if (table != NULL)
		before_living(table);
	if (code == SIGEXIT)
		exit (0);
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if ((int)code == -1)
	{
		errmsg(msg);
		exit (-1);
	}
	else if (code > 0)
	{
		if (msg)
			errmsg(msg);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}
