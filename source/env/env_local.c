/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_local.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:20:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 18:14:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	**env_local(char **local_envp, char **envp, size_t envp_size)
{
	int		i;
	int		j;
	char	**new_envp;

	i = 0;
	j = 0;
	while (local_envp[i])
		i++;
	i += envp_size + 1;
	new_envp = (char **)ft_calloc(i + 1, sizeof(char *));
	if (!new_envp)
		return (NULL);
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
	return (new_envp);
}
