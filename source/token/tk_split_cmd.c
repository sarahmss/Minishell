/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:40 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/14 12:08:43 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*treat_line(char *line, t_cmd_tab *tab)
{
	char		*treated_line;
	char		*stemp;

	if (line == NULL)
		return (NULL);
	stemp = NULL;
	treated_line = NULL;
	treated_line = insert_spaces(line, tab);
	stemp = treated_line;
	treated_line = ft_strtrim(treated_line, " ");
	if (stemp != NULL && stemp != treated_line && stemp != line)
		free(stemp);
	return (treated_line);
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
	line = cmd_line;
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
	env_expand_var(tab->cmd_splitted, tab->session->env);
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

	pos.stemp = treat_line(line, tab);
	tab->cmd_splitted = ft_alocate(pos, delimiter);
	if (tab->cmd_splitted == NULL)
		ft_check_error(1, "ALLOCATING CMD_SPLITTED", tab);
	tab->cmd_splitted = make_splitted(pos.stemp, delimiter, tab);
	head = tk_create_tokens(tab, tab->cmd_splitted);
	free (pos.stemp);
	return (head);
}
