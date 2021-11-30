/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_create_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:51:53 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 17:42:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	create tokens which was separated in cmd_splitted
*/
t_token	*tk_create_tokens(t_cmd_tab *tab, char **cmd_splitted)
{
	int		i;
	t_token	*head;

	i = 0;
	while (cmd_splitted[i] != NULL)
	{
		if (i == 0)
			head = tk_get_new_tok(cmd_splitted[i], tab);
		else
			tk_insert_at_foot(cmd_splitted[i], head, tab);
		i++;
	}
	free_matrix(cmd_splitted);
	cmd_splitted = NULL;
	return (head);
}
