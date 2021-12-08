/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_double_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:03:07 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/08 18:29:02 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	0: no double quotes
	-1: only one double quotes
	1: 2 double quotes
*/
int	dq(char	*line, char c)
{
	char	*dq1;
	char	*dq2;
	char	*temp;
	int		i;

	i = 0;
	dq1 = ft_strchr(line, c);
	if (dq1 == NULL)
		return (0);
	temp = dq1 + 1;
	dq2 = ft_strchr(temp, c);
	if (dq2 == NULL)
		return (-1);
	temp = dq2 + 1;
	if (*temp != '\0')
		i = dq(temp, c);
	if (i == -1)
		return (i);
	return (1);
}

static t_positions	*init_pos(t_cmd_tab *tab, char c, char *cmd_line)
{
	t_positions	*pos;
	char		*temp;

	pos = (t_positions *)malloc(sizeof(t_positions));
	pos->len = ft_arraylen((void **)tab->cmd_splitted) + 1;
	pos->i = 0;
	pos->j = 0;
	pos->k = 0;
	pos->dq1 = ft_strchr(cmd_line, c);
	temp = pos->dq1 + 1;
	pos->temp = ft_strcdup(temp, c);
	pos->stemp = ft_strjoinchar(pos->temp, c);
	free(pos->temp);
	pos->temp = NULL;
	return (pos);
}

char	*make_one(char *s1, char *s2)
{
	char	*sf;
	int		i;
	int		sizef;
	int		j;

	i = 0;
	j = 0;
	sizef = ft_strlen(s1) + ft_strlen(s2) + 2;
	sf = (char *)ft_calloc(sizef, sizeof(char));
	while (i < ft_strlen(s1))
	{
		sf[i] = s1[i];
		i++;
	}
	sf[i] = ' ';
	i++;
	while (i < (sizef - 1))
	{
		sf[i] = s2[j];
		i++;
		j++;
	}
	return (sf);
}

static void	make_one_source(t_positions *pos, char **old, char **new)
{
	new[pos->j] = NULL;
	while (!ft_strcmp(new[pos->j], pos->stemp))
	{
		if (pos->k > 0)
		{
			new[pos->j] = make_one(new[pos->j], old[pos->i]);
			if (pos->temp != NULL)
				free (pos->temp);
			pos->temp = new[pos->j];
			pos->i++;
		}
		else
		{
			new[pos->j] = make_one(old[pos->i], old[pos->i + 1]);
			pos->temp = new[pos->j];
			pos->i += 2;
		}
		pos->k++;
	}
}

void	dq_cmd_tab(t_cmd_tab *tab, char **old, char c, char *cmd_line)
{
	char		**new;
	t_positions	*pos;

	pos = init_pos(tab, c, cmd_line);
	new = (char **)(malloc(sizeof(char *) * pos->len));
	while (old[pos->i] != NULL)
	{
		if (dq(old[pos->i], c) == -1)
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
