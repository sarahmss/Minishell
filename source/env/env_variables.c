/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:26:17 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/27 11:48:13 by smodesto         ###   ########.fr       */
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
		var_split[1] = ft_strtrim(temp + 1, "\"");
	}
	else
	{
		var_split[0] = ft_strdup(str);
		var_split[1] = NULL;
	}
}

/*
	Creates a item to env hash table, where the key = Variable's name
	(ex.: PATH) and values = Variable's value (ex:. "/usr/bin")
*/
t_ht_item	*set_value(t_ht_tab *env, char *str, int mood)
{
	t_ht_item	*variable;
	char		*var_split[2];

	split_var(str, var_split);
	variable = ht_search(env, var_split[0]);
	if (variable != NULL)
	{
		free(variable->value);
		variable->value = ft_strdup(var_split[1]);
		if (mood)
			variable->is_env = true;
		else
			variable->is_env = false;
	}
	else
	{
		variable = ht_insert(env, var_split[0], var_split[1]);
		if (mood)
			variable->is_env = true;
		else
			variable->is_env = false;
	}
	free (var_split[0]);
	free (var_split[1]);
	return (variable);
}
