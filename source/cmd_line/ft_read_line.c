/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 15:17:36 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	0: only char
	1: not only char
*/
int	n_o_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_read_line(t_cmd_tab *tb)
{
	char	*prompt;

	prompt = create_prompt();
	empty_line();
	tb->cmd_line = readline(prompt);
	if (tb->cmd_line == NULL)
		ft_check_error(SIGEXIT, "CTRL+D: EOF", tb);
	else if (n_o_char(tb->cmd_line, '\t') && n_o_char(tb->cmd_line, ' '))
	{
		add_history(tb->cmd_line);
		tb->session->status = 0;
	}
	else
		tb->session->status = ECMDNF;
	no_empty_line(tb);
	free(prompt);
}
