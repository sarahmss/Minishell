/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:37 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/17 14:08:05 by smodesto         ###   ########.fr       */
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

int	valid_piped(char *str)
{
	char	*pipe;

	if (!ft_strchr(str, C_PIPE))
		return (0);
	pipe = ft_strchr(str, C_PIPE);
	if (ft_strlen(pipe) <= 1)
		return (0);
	if ((*(pipe + 2) == '|' && *(pipe + 1) == '|') || !no_only_c(pipe + 1, ' '))
		return (0);
	return (1);
}

void	tokenizer(t_cmd_tab *tab)
{
	if (valid_piped(tab->cmd_line)
		&& !in_qt(tab->cmd_line, C_DQUOTE) && !in_qt(tab->cmd_line, C_SQUOTE))
		tab->piped_cmd = pipe_cmd_line(tab);
	else
		tab->simple_cmd = tk_split_cmd(tab->cmd_line, C_SPACE, tab);
	return ;
}
