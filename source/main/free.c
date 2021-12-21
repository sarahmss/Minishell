/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:26:31 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 14:35:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	free_process(t_process **process)
{
	int			i;
	t_process	*p;

	p = *process;
	if (!p)
		return ;
	if (p->next)
		free_process(&(p->next));
	i = 0;
	while ((p)->input_file[i])
	{
		free((p)->input_file[i]->path);
		free((p)->input_file[i++]);
	}
	i = 0;
	while ((p)->output_file[i])
	{
		free((p)->output_file[i]->path);
		free((p)->output_file[i++]);
	}
	free_matrix((p)->local_env);
	free_matrix((p)->argv);
	free(p->command);
	free(p);
}

static void	free_jobs(t_job **jobs)
{
	t_job	*job;

	job = *jobs;
	if (!job)
		return ;
	if (job->next)
		free_jobs(&(job->next));
	free_process(&(job->process_lst));
	free(job);
	return ;
}

/*
	free memory before living
*/
void	before_living(t_cmd_tab *table)
{
	int	i;

	i = 0;
	if (table->cmd_line != NULL)
		free(table->cmd_line);
	if (table->history != NULL)
		free(table->history);
	if (table->simple_cmd)
		tk_free_lst(table->simple_cmd);
	if (table->piped_cmd)
	{
		while (table->piped_cmd[i] != NULL)
		{
			tk_free_lst(table->piped_cmd[i]);
			i++;
		}
		free(table->piped_cmd);
	}
	if (table->session->jobs)
		free_jobs(&table->session->jobs);
	if (table)
		free(table);
}
