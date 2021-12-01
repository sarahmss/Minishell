/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_insert_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:49:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/01 13:10:10 by smodesto         ###   ########.fr       */
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
		ft_check_error(1, "INSERTING SPACES", tab);
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
	char	operators[2];
	char	*temp;

	operators[0] = C_GREATER;
	operators[1] = C_LESS;
	temp = sup_insert_spaces(line, operators[0], tab);
	new_line = sup_insert_spaces(temp, operators[1], tab);
	if (temp != line && temp != new_line)
		free (temp);
	return (new_line);
}
