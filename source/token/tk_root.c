/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:37 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/06 20:25:27 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	returns 1 if str is between c and 0 if it isn't
*/
int	in_qt(char *str, char c)
{
	char	*q1;
	char	*q2;
	int		ret;

	ret = 0;
	if (dq(str, c) == 1)
	{
		q1 = ft_strchr(str, c);
		q1++;
		q2 = ft_strchr(q1, c);
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
