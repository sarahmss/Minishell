/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:50:15 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 09:51:46 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*

*/
static void make_splitted(char *delimiter, t_cmd_tab *tab)
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
}


