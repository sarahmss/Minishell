/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:03:07 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 14:52:45 by smodesto         ###   ########.fr       */
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

	dq1 = ft_strchr(line, c);
	if (dq1 == NULL)
		return (0);
	temp = dq1 + 1;
	dq2 = ft_strchr(temp, c);
	if (dq2 == NULL)
		return (-1);
	temp = dq2 + 1;
	if (*temp != '\0')
		return(dq(temp, c));
	return (1);
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

void	dq_cmd_tab(t_cmd_tab *tab, char **old, char c)
{
	char		**new;
	int			len;
	t_positions	pos;

	len = ft_arraylen((void **)tab->cmd_splitted) + 1;
	new = (char **)(malloc(sizeof(char *) * len));
	pos.i = 0;
	pos.j = 0;
	while (old[pos.i])
	{
		len = ft_strlen(old[pos.i + 1]) - 1;
		if (old[pos.i][0] == c && old[pos.i + 1][len] == c)
		{
			new[pos.j] = make_one(old[pos.i], old[pos.i + 1]);
			pos.i++;
		}
		else
			new[pos.j] = ft_strdup(old[pos.i]);
		pos.i++;
		pos.j++;
	}
	free_matrix(old);
	new[pos.j] = NULL;
	tab->cmd_splitted = new;
}
