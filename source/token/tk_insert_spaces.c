/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_insert_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:49:11 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/15 20:00:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	eval_line(char *l, char c)
{
	char	*op_pointer;
	int		spaces;
	int		i;

	op_pointer = ft_strchr(l, c);
	spaces = 0;
	i = 0;
	if (op_pointer != NULL)
	{
		while (l[i] != '\0')
		{
			if (l[i] != C_SPACE && l[i] != c && l[i + 1] == c && l[i] != '='
				&& l[i - 2] != '-' && l[i + 2] != ' ' && l[i + 2] != '\0')
				spaces++;
			if (l[i + 1] != C_SPACE && l[i + 1] != c && l[i] == c && c != '\''
				&& c != '\"')
				spaces++;
			i++;
		}
	}
	return (spaces);
}

static char	*create_nl(char *line, char c, t_cmd_tab *tab)
{
	int			new_len;
	char		*new_line;

	new_len = ft_strlen(line) + eval_line(line, c) + 1;
	if (new_len - 1 - ft_strlen(line) == 0)
		return (line);
	new_line = (char *)ft_calloc(sizeof(char), new_len);
	if (!new_line)
		ft_check_error(EALLOC, "INSERTING SPACES", tab);
	return (new_line);
}

static char	*sup_insert_spaces(char *l, char c, t_cmd_tab *tab, int j)
{
	char		*new_line;
	int			i;

	i = 0;
	new_line = create_nl(l, c, tab);
	while (l[i] != '\0' && new_line != l)
	{
		new_line[j] = l[i];
		if (l[i] != ' ' && l[i] != c && l[i + 1] == c && l[i] != '='
			&& l[i - 1] != '-' && l[i + 2] != ' ' && l[i + 2] != '\0')
		{
			j++;
			new_line[j] = ' ';
		}
		if (l[i + 1] != ' ' && l[i + 1] != c && l[i] == c && c != '\''
			&& c != '\"')
		{
			j++;
			new_line[j] = ' ';
		}
		i++;
		j++;
	}
	return (new_line);
}

char	*insert_spaces(char *line, t_cmd_tab *tab)
{
	char	*new_line;
	char	*operators;
	char	*temp;
	int		i;

	operators = ft_strdup("\'\"<>;");
	new_line = NULL;
	temp = line;
	i = 0;
	while (i < ft_strlen(operators))
	{
		if (new_line != NULL)
			temp = new_line;
		if (!in_qt(temp, '\'', operators[i]) && !in_qt(temp, '"', operators[i]))
			new_line = sup_insert_spaces(temp, operators[i], tab, 0);
		if (temp != NULL && temp != line && temp != new_line)
			free (temp);
		i++;
	}
	free (operators);
	return (new_line);
}
