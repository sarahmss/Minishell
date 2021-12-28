/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:59:23 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 13:31:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Runs through *envp[] while putting the environment variables in a hash table.
	echo $USER
*/
t_ht_tab	*load_env(char *envp[])
{
	t_ht_tab	*env;
	int			i;

	i = 0;
	env = create_table((int)HT_SIZE_ENV);
	while (envp[i])
	{
		set_value(env, envp[i], 1);
		i++;
	}
	return (env);
}
