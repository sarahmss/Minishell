/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_insert_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:49:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 20:56:02 by smodesto         ###   ########.fr       */
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
			if (l[i] != C_SPACE && l[i] != c && l[i + 1] == c)
				spaces++;
			if (l[i + 1] != C_SPACE && l[i + 1] != c && l[i] == c)
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

static char	*sup_insert_spaces(char *line, char c, t_cmd_tab *tab)
{
	char		*new_line;
	int			i;
	int			j;

	i = 0;
	j = 0;
	new_line = create_nl(line, c, tab);
	while (line[i] != '\0' && new_line != line)
	{
		new_line[j] = line[i];
		if (line[i] != C_SPACE && line[i] != c && line[i + 1] == c)
		{
			j++;
			new_line[j] = ' ';
		}
		if (line[i + 1] != C_SPACE && line[i + 1] != c && line[i] == c)
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

	operators = ft_strdup("<>();*+");
	new_line = NULL;
	temp = line;
	i = 0;
	while (i < ft_strlen(operators))
	{
		if (new_line != NULL)
			temp = new_line;
		new_line = sup_insert_spaces(temp, operators[i], tab);
		if (temp != NULL && temp != line && temp != new_line)
			free (temp);
		i++;
	}
	free (operators);
	return (new_line);
}
