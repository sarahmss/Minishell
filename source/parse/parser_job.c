/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:38:19 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 20:40:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	push_job(t_job **job, t_job *new)
{
	t_job	*temp;

	if (*job == NULL)
		*job = new;
	else
	{
		temp = *job;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

static t_job	*parse_job(t_token **tokens, int i)
{
	t_job		*job;
	t_process	*head;
	t_process	*command;	

	job = ft_calloc(1, sizeof(t_job));
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
	job->process_lst = head;
	return (job);
}

t_job	*parser(t_cmd_tab *tb)
{
	t_job		*jobs;
	t_token		**tokens;
	int			mood;

	jobs = NULL;
	mood = 1;
	if (tb->piped_cmd != NULL)
	{
		tokens = tb->piped_cmd;
		mood = 0;
	}
	else
		tokens = &tb->simple_cmd;
	push_job(&jobs, parse_job(tokens, mood));
	return (jobs);
}
