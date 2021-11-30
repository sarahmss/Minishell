/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 12:13:49 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	**make_splitted(char delimiter, t_cmd_tab *tab)
{
	int		pos;
	char	*token;
	char	*line;
	char	**tokens;

	pos = 0;
	line = tab->cmd_line;
	token = ft_strtok(line, delimiter);
	tokens = tab->cmd_splitted;
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		token = ft_strtok(NULL, delimiter);
	}
	tokens[pos] = NULL;
	if (dq(tab->cmd_line) == -1)
		ft_check_error(1, "MISSING DOUBLE QUOTES", tab);
	else if (dq(tab->cmd_line) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted);
	return (tab->cmd_splitted);
}

static char	**ft_alocate(t_positions pos, char sep)
{
	char	**splitted_matrix;

	pos.k = 0;
	while (*pos.stemp)
	{
		if (*pos.stemp != sep)
		{
			while (*pos.stemp != sep && *pos.stemp)
				pos.stemp++;
			pos.k++;
		}
		if (*pos.stemp)
			pos.stemp++;
	}
	splitted_matrix = (char **)ft_calloc((pos.k + 1), sizeof(char *));
	if (!splitted_matrix)
		return (NULL);
	return (splitted_matrix);
}

/*
	Parse that line into a list of arguments.
*/
char	**ft_split_cmd(char *line, char delimiter, t_cmd_tab *tab)
{
	t_positions	pos;

	if (line == NULL)
		return (NULL);
	pos.stemp = (char *)line;
	tab->cmd_splitted = ft_alocate(pos, delimiter);
	if (tab->cmd_splitted == NULL)
		ft_check_error(1, "ALLOCATING CMD_SPLITTED", tab);
	tab->cmd_splitted = make_splitted(delimiter, tab);
	if (tab->cmd_splitted == NULL)
		ft_check_error(1, "ALLOCATING CMD_SPLITTED", tab);
	return (tab->cmd_splitted);
}
