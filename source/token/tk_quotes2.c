/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_quotes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:19:18 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/06 23:04:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	check_quotes(char *cmd_line, t_cmd_tab *tab)
{
	char	quotes[2];

	quotes[0] = C_DQUOTE;
	quotes[1] = C_SQUOTE;
	if (dq(cmd_line, quotes[0]) == -1)
		return (ft_check_error(EUNFQT, "MISSING DOUBLE QUOTES\n", NULL));
	if (dq(cmd_line, quotes[0]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[0], cmd_line);
	if (dq(cmd_line, quotes[1]) == -1)
		return (ft_check_error(EUNFQT, "MISSING SINGLE QUOTES\n", NULL));
	if (dq(cmd_line, quotes[1]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[1], cmd_line);
	return (0);
}

int	check_quotes2(char *cmd_line)
{
	char	quotes[2];

	quotes[0] = C_DQUOTE;
	quotes[1] = C_SQUOTE;
	if (dq(cmd_line, quotes[0]) == -1)
		return (ft_check_error(EUNFQT, "MISSING DOUBLE QUOTES\n", NULL));
	if (dq(cmd_line, quotes[1]) == -1)
		return (ft_check_error(EUNFQT, "MISSING SINGLE QUOTES\n", NULL));
	return (0);
}

/*
	0: no quotes
	-1: only one quotes
	1: 2 quotes
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

static char	*leave(char *before_qt, char *after_qt, char *new_line, char *temp)
{
	if (new_line)
		free (new_line);
	if (temp)
		free (temp);
	if (before_qt)
		free (before_qt);
	if (after_qt)
		free (after_qt);
	return (NULL);
}

char	*remove_qt_inside_qt(char *str, char *c)
{
	char	*new_line;
	char	*temp;
	char	*before_qt;
	char	*after_qt;

	new_line = NULL;
	if (ft_strchr(str, *c) == NULL)
		return (NULL);
	before_qt = ft_strcdup(str, *c);
	after_qt = ft_strdup(ft_strrchr(str, *c) + 1);
	temp = ft_strtrim(str, before_qt);
	free (new_line);
	new_line = ft_strtrim(temp, after_qt);
	free (temp);
	temp = ft_strtrim(new_line, c);
	if (temp == NULL || ft_strchr(temp, *c) == NULL)
		return (leave(before_qt, after_qt, new_line, temp));
	free (new_line);
	new_line = temp;
	temp = str_replace(new_line, c, "");
	free (new_line);
	new_line = ft_join_var(5, before_qt, c, temp, c, after_qt);
	leave(before_qt, after_qt, NULL, temp);
	return (new_line);
}
