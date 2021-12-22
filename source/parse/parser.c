/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parserc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:40:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 14:41:00 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static t_process	*simple_or_piped(t_token **tokens, int i)
{
	t_process	*head;
	t_process	*command;
	t_process	*process_lst;

	head = NULL;
	if (i == 0)
	{
		while (tokens[i] != NULL)
		{
			command = parse_command(&tokens[i]);
			push_process(&head, command);
			i++;
		}
	}
	else
	{
		command = parse_command(tokens);
		push_process(&head, command);
	}
	process_lst = head;
	return (process_lst);
}

t_process	*parser(t_cmd_tab *tb)
{
	t_token		**tokens;
	int			mood;
	t_process	*process;

	mood = 1;
	if (tb->piped_cmd != NULL)
	{
		tokens = tb->piped_cmd;
		mood = 0;
	}
	else
		tokens = &tb->simple_cmd;
	process = simple_or_piped(tokens, mood);
	return (process);
}
