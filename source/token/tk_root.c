/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:37 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 21:04:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	in_qt(char *cmd_line, char c)
{
	char	*q1;
	char	*q2;
	int		ret;

	ret = 0;
	if (dq(cmd_line, c) == 1)
	{
		q1 = ft_strchr(cmd_line, c);
		q1++;
		q2 = ft_strchr(cmd_line, c);
		while (*q1 != *q2)
		{
			if (*q1++ == C_PIPE)
				ret = 1;
		}
	}
	return (ret);
}

void	tokenizer(t_cmd_tab *tab)
{
	if (ft_strchr(tab->cmd_line, C_PIPE)
		&& !in_qt(tab->cmd_line, C_DQUOTE) && !in_qt(tab->cmd_line, C_SQUOTE))
		tab->piped_cmd = pipe_cmd_line(tab);
	else
		tab->simple_cmd = tk_split_cmd(tab->cmd_line, C_SPACE, tab);
	return ;
}
