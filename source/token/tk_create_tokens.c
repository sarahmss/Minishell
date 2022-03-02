/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_create_tokens.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 08:51:53 by smodesto          #+#    #+#             */
/*   Updated: 2022/03/01 15:43:55 by coder            ###   ########.fr       */
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
	if (tab->cmd_splitted != NULL)
		free_matrix(tab->cmd_splitted);
	tk_define_types(head);
	return (head);
}
