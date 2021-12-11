/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:26:17 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/10 23:04:30 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	ex: PATH="/usr/bin" ==> [var_split[0] == PATH|var_split[1] == "/usr/bin"]
*/
void	split_var(char *str, char *var_split[])
{
	char	*temp;

	temp = ft_strchr(str, '=');
	if (temp)
	{
		var_split[0] = ft_strtok(str, '=');
		var_split[1] = ft_strdup(temp + 1);
	}
	else
	{
		var_split[0] = ft_strdup(str);
		var_split[1] = NULL;
	}
}

/*
	Creates a item to env hash table, where the key = Variable's name (ex.: PATH) and values = Variable's value (ex:. "/usr/bin")
*/
char	*set_value(t_ht_tab *env, char *str, bool is_env)
{
	t_variable	*variable;
	char		*var_split[2];

	split_var(str, var_split);
	variable = ht_search(env, var_split[0]);
	if (variable != NULL)
	{
		variable->value = var_split[1];
		variable->env = is_env;
	}
	else
	{
		variable = malloc(sizeof(*variable));
		if (!variable)
			return (NULL);
		variable->value = var_split[1];
		variable->env = is_env;
		ht_insert(env, var_split[0], variable);
	}
	free(var_split[0]);
	return (var_split[1]);
}
