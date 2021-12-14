/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_quotes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:19:18 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/11 10:22:23 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	check_quotes(char *cmd_line, t_cmd_tab *tab)
{
	char	quotes[2];

	quotes[0] = C_DQUOTE;
	quotes[1] = C_SQUOTE;
	if (dq(cmd_line, quotes[0]) == -1)
		ft_check_error(1, "MISSING DOUBLE QUOTES", tab);
	if (dq(cmd_line, quotes[0]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[0], cmd_line);
	if (dq(cmd_line, quotes[1]) == -1)
		ft_check_error(1, "MISSING SINGLE QUOTES", tab);
	if (dq(cmd_line, quotes[1]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[1], cmd_line);
}

/*
	0: no double quotes
	-1: only one double quotes
	1: 2 double quotes
*/
int	dq(char	*line, char c)
{
	char	*dq1;
	char	*dq2;
	char	*temp;
	int		i;

	i = 0;
	dq1 = ft_strchr(line, c);
	if (dq1 == NULL)
		return (0);
	temp = dq1 + 1;
	dq2 = ft_strchr(temp, c);
	if (dq2 == NULL)
		return (-1);
	temp = dq2 + 1;
	if (*temp != '\0')
		i = dq(temp, c);
	if (i == -1)
		return (i);
	return (1);
}
