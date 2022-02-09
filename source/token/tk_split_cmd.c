/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_split_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 11:22:40 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/31 10:59:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*treat_line(char *line, t_cmd_tab *tab)
{
	char		*treated_line;
	char		*stemp;

	tab->session->errcd = check_quotes2(line);
	if (line == NULL || tab->session->errcd != 0)
		return (NULL);
	if ((c_in_c('\"', line)) || (c_in_c('\'', line)))
		treated_line = substitute_quotes(line);
	else
		treated_line = line;
	stemp = treated_line;
	treated_line = insert_spaces(treated_line, tab);
	if (stemp != NULL && stemp != treated_line && stemp != line)
		free(stemp);
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
		if (ft_strlen(token))
		{
			tokens[pos] = token;
			pos++;
		}
		else
			free(token);
		token = ft_strtok(NULL, delimiter);
	}
	tokens[pos] = NULL;
	tab->session->errcd = check_quotes(line, tab);
	env_expand_var(tab->cmd_splitted, tab->session->env, tab->session->stat);
	return (tab->cmd_splitted);
}

static void	skip_spacesqt(t_positions *p)
{
	p->stemp++;
	while ((*p->stemp != '\'' || *p->stemp != '\"') && *p->stemp == ' ')
	{
		p->k++;
		p->stemp++;
	}
	p->stemp++;
	p->k++;
}

/*
	Allocates space for the matrix divided by the sep delimiter
*/
static char	**ft_alocate(t_positions p, char sep)
{
	char	**splitted_matrix;

	p.k = 0;
	while (*p.stemp)
	{
		if ((*p.stemp == '\'' || *p.stemp == '\"') && (*(p.stemp + 1) == ' '))
			skip_spacesqt(&p);
		else if (*p.stemp != sep)
		{
			while (*p.stemp != sep && *p.stemp)
				p.stemp++;
			p.k++;
		}
		if (*p.stemp)
			p.stemp++;
	}
	splitted_matrix = (char **)ft_calloc((p.k + 1), sizeof(char *));
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
	if (pos.stemp == NULL)
		return (NULL);
	tab->cmd_splitted = ft_alocate(pos, delimiter);
	if (tab->cmd_splitted == NULL)
		ft_check_error(EALLOC, "ALLOCATING CMD_SPLITTED", NULL);
	tab->cmd_splitted = make_splitted(pos.stemp, delimiter, tab);
	head = tk_create_tokens(tab, tab->cmd_splitted);
	free (pos.stemp);
	return (head);
}
