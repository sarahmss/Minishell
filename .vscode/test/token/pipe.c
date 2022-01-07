/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 09:23:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 09:36:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	**pipe_exists(char *str)
{
	char	**split_pipe;

	split_pipe = (char **)malloc(sizeof(char *));
	if (!split_pipe)
		return (NULL);
	split_pipe[0] = ft_strtok(str, "|");
	if (split_pipe[0] == NULL)
		return (NULL);
	split_pipe[1] = ft_strtok(NULL, "|");
	if (split_pipe[1] == NULL)
	{
		if (split_pipe[0])
			free(split_pipe[0]);
		return (NULL);
	}
	return (split_pipe);
}
