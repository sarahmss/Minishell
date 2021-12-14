/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_root.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:47:37 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/11 10:06:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	tokenizer(t_cmd_tab *tab)
{
	if (ft_strchr(tab->cmd_line, C_PIPE))
		tab->piped_cmd = pipe_cmd_line(tab);
	else
		tab->simple_cmd = tk_split_cmd(tab->cmd_line, C_SPACE, tab);
	return ;
}
