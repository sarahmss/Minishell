/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expansion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 23:05:02 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/15 19:28:16 by smodesto         ###   ########.fr       */
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

static char	*expand_exit_stts(char *str, int stts, int *j)
{
	char		*new_line;
	char		*temp;

	if (WIFEXITED(stts) && stts != ECMDNF && stts != SINT && stts != SQUIT)
		temp = ft_itoa(WEXITSTATUS(stts));
	else
		temp = ft_itoa(stts);
	new_line = str_replace(str, "$?", temp);
	free (temp);
	if (ft_strlen(new_line) < 2)
		j++;
	else
		j += 2;
	free(str);
	return (new_line);
}

static char	*find_value(t_ht_tab *env, char *var_name)
{
	t_ht_item	*variable;

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
		free (str);
		return (ft_strdup("  "));
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
void	env_expand_var(char **s, t_ht_tab *env, int status)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0' && ft_strchr(s[i], '$'))
		{
			if (s[i][j] == '$' && (s[i][j + 1] == '\0' || s[i][j + 1] == ' '))
				s[i][j] = '$';
			else if (s[i][j] == '$' && s[i][j + 1] == '?')
				s[i] = expand_exit_stts(s[i], status, &j);
			else if (s[i][j] == '$' && !dq(s[i], '\''))
				s[i] = assign_value(s[i], env, j);
			j++;
		}
		i++;
	}
}
