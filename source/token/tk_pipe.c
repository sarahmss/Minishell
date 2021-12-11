/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:23:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/08 19:47:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	**split_pipe(char *str)
{
	char	**split_pipe;

	split_pipe = (char **)ft_calloc(sizeof(char *), 3);
	if (!split_pipe)
		return (NULL);
	split_pipe[0] = ft_strtok(str, C_PIPE);
	if (split_pipe[0] == NULL)
		return (NULL);
	split_pipe[1] = ft_strtok(NULL, C_PIPE);
	if (split_pipe[1] == NULL)
	{
		if (split_pipe[0])
			free(split_pipe[0]);
		return (NULL);
	}
	split_pipe[2] = NULL;
	return (split_pipe);
}

t_token	**pipe_cmd_line(t_cmd_tab *tab)
{
	char	**split;
	t_token	**pipe;

	pipe = (t_token **)malloc(sizeof(t_token *) * 2);
	if (!pipe)
		ft_check_error(1, "CREATING PIPED CMD LINE", tab);
	split = split_pipe(tab->cmd_line);
	pipe[0] = tk_split_cmd(split[0], C_SPACE, tab);
	pipe[1] = tk_split_cmd(split[1], C_SPACE, tab);
	free_matrix(split);
	return (pipe);
}
