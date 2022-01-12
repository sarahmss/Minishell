/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_quotes1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:03:07 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/12 23:14:05 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

char	*substitute_quotes(char *line)
{
	char		*treated_line;
	char		*stemp;

	stemp = NULL;
	treated_line = NULL;
	stemp = remove_qt_inside_qt(line, "\"");
	if (stemp == NULL)
		stemp = line;
	treated_line = remove_qt_inside_qt(stemp, "\'");
	if (stemp != line && treated_line != NULL && stemp != NULL)
		free (stemp);
	if (treated_line != NULL)
		return (treated_line);
	else if (stemp != NULL)
		return (stemp);
	else
		return (line);
}

static void	suport(t_positions *pos, char *temp, char c)
{
	if (*(pos->temp + 1) != ' ' && *(pos->temp + 1) != '\0')
	{
		while ((pos->temp[pos->i] != ' ') && (pos->temp[pos->i] != '\0'))
			pos->i++;
		pos->stemp = ft_calloc(sizeof(char), ft_strlen(temp) + pos->i + 2);
		pos->stemp = ft_strncpy(pos->stemp, pos->dq1, ft_strlen(temp) + pos->i);
	}
	else
	{
		pos->temp = ft_strcdup(temp, c);
		pos->stemp = ft_strjoinchar(pos->temp, c);
		free(pos->temp);
		pos->temp = NULL;
	}
}

static t_positions	*init_pos(t_cmd_tab *tab, char c, char *cmd_line)
{
	t_positions	*pos;
	char		*temp;

	pos = (t_positions *)malloc(sizeof(t_positions));
	pos->len = ft_arraylen((void **)tab->cmd_splitted) + 1;
	pos->i = 1;
	pos->j = 0;
	pos->k = 0;
	pos->dq1 = ft_strchr(cmd_line, c);
	temp = pos->dq1 + 1;
	pos->temp = ft_strchr(temp, c);
	suport(pos, temp, c);
	pos->i = 0;
	return (pos);
}

static int	check_spaces(char c, char *cmd_line)
{
	char	*temp;

	temp = ft_strchr(cmd_line, c);
	temp = ft_strcdup((temp + 1), c);
	if (no_only_c(temp, ' '))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

void	dq_cmd_tab(t_cmd_tab *tab, char **old, char c, char *cmd_line)
{
	char		**new;
	t_positions	*pos;

	pos = init_pos(tab, c, cmd_line);
	new = (char **)(malloc(sizeof(char *) * pos->len));
	while (old[pos->i] != NULL)
	{
		if (dq(old[pos->i], c) == -1 && check_spaces(c, cmd_line) == 1)
			make_one_source(pos, old, new);
		else
		{
			new[pos->j] = ft_strdup(old[pos->i]);
			pos->i++;
		}
		pos->j++;
	}
	free_matrix(old);
	new[pos->j] = NULL;
	tab->cmd_splitted = new;
	free (pos->stemp);
	free (pos);
}
