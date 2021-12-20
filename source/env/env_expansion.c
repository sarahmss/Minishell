/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:05:02 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/14 21:36:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*find_var_name(char *str, int j)
{
	char		*var_name;
	int			end;
	int			begin;
	char		*temp;

	end = 0;
	if ((*str == '"' && *str + 1 == '$')
		|| (str[j] == '{' && str[j + 1] == '$'))
		begin = 0;
	else
		begin = j;
	temp = str + begin;
	while (ft_isalnum(temp[end]) || temp[end] == '$' || temp[end] == '}'
		|| temp[end] == '{' || temp[end] == '"')
		end++;
	var_name = ft_substr(str, begin, end + begin);
	if (ft_strchr(var_name, ' '))
	{
		temp = var_name;
		var_name = ft_strcdup(var_name, ' ');
		free (temp);
	}
	return (var_name);
}

static char	*literal_value(char *str)
{
	char		*new_line;
	char		*temp;

	temp = ft_strchr(str, '$');
	new_line = str_replace(str, temp - 1, temp);
	free (str);
	return (new_line);
}

static char	*find_value(t_ht_tab *env, char *var_name)
{
	t_variable	*variable;

	variable = ht_search(env, var_name);
	if (variable)
		return (variable->value);
	else
		return (NULL);
}

char	*assign_value(char *str, t_ht_tab *env, int j)
{
	char		*new_line;
	char		*var_name;
	char		*cl_var;
	char		*value;

	var_name = find_var_name(str, j);
	cl_var = ft_strtrim(var_name, " {}$\"");
	value = find_value(env, cl_var);
	if (value == NULL)
	{
		if (var_name != str)
			free(var_name);
		if (cl_var)
			free(cl_var);
		return (str);
	}
	new_line = str_replace(str, var_name, value);
	if (var_name != str)
		free(var_name);
	if (cl_var)
		free(cl_var);
	free (str);
	return (new_line);
}

/*
	1. $variable || ${variable} || "$variable" || "${variable}"
		echo $USER ${USER} "$USER" "${USER}"
*/
void	env_expand_var(char **cmd_splitted, t_ht_tab *env)
{
	int		i;
	int		j;

	i = 0;
	while (cmd_splitted[i] != NULL)
	{
		j = 0;
		while (cmd_splitted[i][j] != '\0')
		{
			if (cmd_splitted[i][j] == '\\' && cmd_splitted[i][j + 1] == '$')
			{
				cmd_splitted[i] = literal_value(cmd_splitted[i]);
				j += 2;
			}
			else if (cmd_splitted[i][j] == '$')
				cmd_splitted[i] = assign_value(cmd_splitted[i], env, j);
			j++;
		}
		i++;
	}
}