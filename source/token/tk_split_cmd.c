/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/01 13:10:15 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	check_quotes(char *cmd_line, t_cmd_tab *tab)
{
	char	quotes[2];

	quotes[0] = C_DQUOTE;
	quotes[1] = C_SQUOTE;
	if (dq(cmd_line, quotes[0]) == -1)
		ft_check_error(1, "MISSING DOUBLE QUOTES", tab);
	if (dq(cmd_line, quotes[0]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[0]);
	if (dq(cmd_line, quotes[1]) == -1)
		ft_check_error(1, "MISSING SINGLE QUOTES", tab);
	if (dq(cmd_line, quotes[1]) == 1)
		dq_cmd_tab(tab, tab->cmd_splitted, quotes[1]);
}

/*
	Uses strtok to fill the matrix
*/
static char	**make_splitted(char *cmd_line, char delimiter, t_cmd_tab *tab)
{
	int		pos;
	char	*token;
	char	*line;
	char	**tokens;

	pos = 0;
	line = insert_spaces(cmd_line, tab);
	line = ft_strtrim(line, " ");
	token = ft_strtok(line, delimiter);
	tokens = tab->cmd_splitted;
	while (token != NULL)
	{
		tokens[pos] = token;
		pos++;
		token = ft_strtok(NULL, delimiter);
	}
	tokens[pos] = NULL;
	check_quotes(line, tab);
	return (tab->cmd_splitted);
}

/*
	Allocates space for the matrix divided by the sep delimiter
*/
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
	Main function to split the command line
*/
t_token	*tk_split_cmd(char *line, char delimiter, t_cmd_tab *tab)
{
	t_positions	pos;
	t_token		*head;

	if (line == NULL)
		return (NULL);
	pos.stemp = (char *)line;
	tab->cmd_splitted = ft_alocate(pos, delimiter);
	if (tab->cmd_splitted == NULL)
		ft_check_error(1, "ALLOCATING CMD_SPLITTED", tab);
	tab->cmd_splitted = make_splitted(line, delimiter, tab);
	if (tab->cmd_splitted == NULL)
		ft_check_error(1, "ALLOCATING CMD_SPLITTED", tab);
	head = tk_create_tokens(tab, tab->cmd_splitted);
	return (head);
}
