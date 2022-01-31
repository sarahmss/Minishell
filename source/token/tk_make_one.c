/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_make_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:11:31 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/31 10:54:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*make_one(char *s1, char *s2)
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

void	make_one_source(t_positions *pos, char **old, char **new)
{
	new[pos->j] = NULL;
	while (!ft_strcmp(new[pos->j], pos->stemp) && old[pos->i])
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
