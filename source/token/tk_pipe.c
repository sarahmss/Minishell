/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:23:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 17:57:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	count_pipes(char *str)
{
	int		pipes;
	char	*temp;

	pipes = 0;
	temp = ft_strchr(str, '|');
	while (temp)
	{
		temp = temp + 1;
		temp = ft_strchr(temp, '|');
		pipes++;
	}
	return (pipes);
}

char	**split_pipe(char *str, int times)
{
	char	**split_pipe;
	int		i;

	i = 1;
	split_pipe = (char **)ft_calloc(sizeof(char *), times);
	if (!split_pipe)
		return (NULL);
	split_pipe[0] = ft_strtok(str, C_PIPE);
	while (i < times - 1)
	{
		split_pipe[i] = ft_strtok(NULL, C_PIPE);
		if (split_pipe[i] == NULL)
		{
			if (split_pipe[i])
				free(split_pipe[i - 1]);
			return (NULL);
		}
		i++;
	}
	split_pipe[i] = NULL;
	return (split_pipe);
}

t_token	**pipe_cmd_line(t_cmd_tab *tab)
{
	char	**split;
	t_token	**pipe;
	int		times;
	int		i;

	i = 0;
	times = count_pipes(tab->cmd_line);
	pipe = (t_token **)malloc(sizeof(t_token *) * times + 2);
	if (!pipe)
		ft_check_error(EALLOC, "CREATING PIPED CMD LINE", tab);
	split = split_pipe(tab->cmd_line, times + 2);
	while (i < times + 1)
	{
		pipe[i] = tk_split_cmd(split[i], C_SPACE, tab);
		i++;
	}
	free_matrix(split);
	pipe[i] = NULL;
	return (pipe);
}
