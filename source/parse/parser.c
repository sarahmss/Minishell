/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:40:56 by smodesto          #+#    #+#             */
/*   Updated: 2022/03/01 21:25:44 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	push_process(t_process **lst, t_process *new_p)
{
	t_process	*last;

	if (*lst == NULL)
		*lst = new_p;
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new_p;
		new_p->prev = last;
	}
}

char	*sup_trim(char *word)
{
	char	*qts;
	char	qt;
	char	*ret;

	ret = NULL;
	qt = 0;
	if (ft_strchr(word, C_DQUOTE))
		qt = C_DQUOTE;
	else if (ft_strchr(word, C_SQUOTE))
		qt = C_SQUOTE;
	if (qt == 0)
		return (ft_strdup(word));
	qts = ft_strchr(word, qt);
	if (qts == NULL || ft_strchr(qts + 1, qt) == NULL)
		return (ft_strdup(word));
	qts = ft_strcdup(qts + 1, qt);
	if (ft_strlen(qts) > 2 && no_only_c(qts, qt) && no_only_c(qts + 1, C_SPACE))
		ret = ft_strtrim(word, "\'\" ");
	else
		ret = ft_strdup(word);
	free (qts);
	return (ret);
}

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
