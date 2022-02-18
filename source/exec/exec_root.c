/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgana <morgana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/17 22:19:08 by morgana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	def_fdin(int tmpin, t_session *s)
{
	int		fdin;
	t_file	*file;
	int		i;

	i = -1;
	while (s->process_lst->input_file[i + 1])
		i++;
	file = s->process_lst->input_file[i];
	if (file && file->flags == 2)
	{
		fdin = open(file->path, O_RDONLY);
		file->fd = fdin;
	}
	else if (file)
	{
		fdin = redir(file->path, s);
		file->fd = fdin;
	}
	else
		fdin = dup(tmpin);
	return (fdin);
}

void	exec_cmd(t_session *s, t_cmd_tab *tb)
{
	int		tmpin;
	int		tmpout;
	int		fdin;

	tmpin = dup(0);
	tmpout = dup(1);
	fdin = def_fdin(tmpin, s);
	if (fdin == -1)
		perror("error");
	while (s->process_lst != NULL)
	{
		pipe_create(fdin, tmpout, s);
		run_command(s, tb);
		s->process_lst = s->process_lst->next;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
}

int	execute_root(t_session *session, t_cmd_tab *tb)
{
	char		**local_env;
	int			assign;
	t_process	*process_head;

	assign = 0;
	local_env = session->process_lst->local_env;
	assign = env_assign(local_env, session->env);
	if (session->child_envp != NULL)
		free_matrix(session->child_envp);
	session->child_envp = env_local(session->env);
	if (!assign)
	{
		process_head = session->process_lst;
		exec_cmd(session, tb);
		session->process_lst = process_head;
	}
	return (1);
}
