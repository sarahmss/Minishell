/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:17:15 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/17 13:48:57 by smodesto         ###   ########.fr       */
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
	int		i;

	i = 0;
	if (tb->simple_cmd != NULL)
	{
		if (validate_tokens(tb->simple_cmd) == -1)
			return (ft_check_error(ESYNTAX, "bad syntax", NULL));
	}
	else if (tb->piped_cmd != NULL)
	{
		while (tb->piped_cmd[i] != NULL)
		{
			if (validate_tokens(tb->piped_cmd[i]) == -1)
				return (ft_check_error(ESYNTAX, "bad syntax", NULL));
			i++;
		}
	}
	return (0);
}
