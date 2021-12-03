/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:37 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/02 21:04:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	tokenizer(t_cmd_tab *tab)
{
	t_token	**piped_cmd;
	t_token	*simple_cmd;

	piped_cmd = NULL;
	simple_cmd = NULL;
	if (ft_strchr(tab->cmd_line, C_PIPE))
		piped_cmd = pipe_cmd_line(tab);
	else
		simple_cmd = tk_split_cmd(tab->cmd_line, C_SPACE, tab);
	if (simple_cmd)
		tk_free_lst(simple_cmd);
	if (piped_cmd)
	{
		tk_free_lst(piped_cmd[0]);
		tk_free_lst(piped_cmd[1]);
	}
}
