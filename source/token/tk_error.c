/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:17:15 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 21:12:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Is the order right? [oprional]
	cmd [arg]* [| cmd [arg]*] [[> fd] [< fd] [<< fd] [>> fd]]
	cmd : T_WORD || T_BUILTIN
*/
int	validate_tokens(t_token *tk)
{
	int			status;
	t_token		*t;

	status = 0;
	t = tk;
	while (t)
	{
		if ((t->type != T_WORD && (!t->next || t->next->type != T_WORD))
			&& (t->type != T_BUILTIN && (!t->next || t->next->type != T_BUILTIN)
			))
				status = -1;
		t = t->next;
	}
	return (status);
}

int	token_error(t_cmd_tab *tb)
{
	int		status;
	int		i;

	i = 0;
	if (tb->simple_cmd != NULL)
		status = validate_tokens(tb->simple_cmd);
	else if (tb->piped_cmd != NULL)
	{
		while (tb->piped_cmd[i] != NULL)
		{
			status = validate_tokens(tb->piped_cmd[i]);
			i++;
		}
	}
	return (status);
}
