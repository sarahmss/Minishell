/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:49:27 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/25 17:53:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Runs through *envp[] while putting the environment variables in the hash table env.
*/
int	env_assign(char *envp[], t_ht_tab *env)
{
	int			i;
	int		assign;

	i = 0;
	assign = 0;
	while (envp[i])
	{
		if (set_value(env, envp[i]))
			assign = 1;
		i++;
	}
	return (assign);
}
