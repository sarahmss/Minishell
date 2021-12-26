/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_local.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:20:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 01:20:35 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	**env_local(char **local_envp, char **envp, int envp_size)
{
	int		j;
	char	**new_envp;

	j = 0;
	while (local_envp[j])
		j++;
	j += envp_size + 1;
	new_envp = (char **)ft_calloc(j, sizeof(char *));
	if (!new_envp)
		return (NULL);
	j = 0;
	while (envp[j])
	{
		new_envp[j] = ft_strdup(envp[j]);
		j++;
	}
	j = 0;
	while (local_envp[j])
	{
		new_envp[envp_size + j] = ft_strdup(local_envp[j]);
		j++;
	}
	new_envp[envp_size + j] = NULL;
	return (new_envp);
}
