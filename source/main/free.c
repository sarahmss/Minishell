/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:26:31 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/25 19:03:08 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	free_mat(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
}

static void	free_file(t_file *file[])
{
	int	i;

	i = 0;
	if (*file)
	{
		while (file[i] != NULL)
		{
			free(file[i]->path);
			free(file[i]);
			i++;
		}
	}
}

static void	free_process(t_process **process)
{
	t_process	*p;

	p = *process;
	if (p->next)
		free_process(&(p->next));
	free_file(p->input_file);
	free_file(p->output_file);
	if (p->local_env[0] != NULL)
		free_mat(p->local_env);
	if (p->argv[0] != NULL)
		free_mat(p->argv);
	if (p->command != NULL)
		free(p->command);
	free(p);
}

/*
	free session before exiting shell
*/
void	free_session(t_session *session)
{
	free_ht_tab(session->env);
	free_mat(session->child_envp);
	free(session->child_envp);
	free (session);
	session = NULL;
}

/*
	free memory before prompting again
*/
void	before_living(t_cmd_tab *table)
{
	int	i;

	i = 0;
	if (!table)
		return ;
	if (table->cmd_line != NULL)
		free(table->cmd_line);
	if (table->history != NULL)
		free(table->history);
	if (table->simple_cmd != NULL)
		tk_free_lst(table->simple_cmd);
	if (table->piped_cmd != NULL)
	{
		while (table->piped_cmd[i] != NULL)
		{
			tk_free_lst(table->piped_cmd[i]);
			i++;
		}
		free(table->piped_cmd);
	}
	if (table->session && table->session->process_lst)
		free_process(&(table->session->process_lst));
	free(table);
}
