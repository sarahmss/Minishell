/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_local.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:20:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 14:24:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	**env_local(t_ht_tab *env)
{
	char	**new_envp;
	char	*var;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HT_SIZE_ENV)
	{
		if (env->items[i] && env->items[i]->is_env == true)
			j++;
		i++;
	}
	new_envp = (char **)ft_calloc(j + 1, sizeof(char *));
	i = 0;
	j = 0;
	while (i < HT_SIZE_ENV)
	{
		if (env->items[i] && env->items[i]->is_env == true)
		{
			var = ft_join_var(3, env->items[i]->key, "=", env->items[i]->value);
			new_envp[j] = var;
			j++;
		}
		i++;
	}
	new_envp[j] = NULL;
	return (new_envp);
}
