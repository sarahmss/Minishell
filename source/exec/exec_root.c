/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/22 15:18:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static t_file	*def_file(t_session *s)
{
	int			i;
	t_file		*file;

	i = -1;
	file = NULL;
	while (s->process_lst->input_file[i + 1])
		i++;
	if (s->process_lst->input_file[i])
		file = s->process_lst->input_file[i];
	else if (s->process_lst->next && ft_strcmp(s->process_lst->command, "cat")
		&& file == NULL && s->process_lst->next->input_file[0] != NULL)
	{
		i = -1;
		while (s->process_lst->next->input_file[i + 1])
			i++;
		file = s->process_lst->next->input_file[i];
		s->process_lst->argv[1] = ft_strdup(file->path);
	}
	return (file);
}

static int	def_fdin(int tmpin, t_session *s, int change, int old_fd)
{
	int			fdin;
	t_file		*file;

	file = def_file(s);
	fdin = -2;
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
	else if (change == 0)
		fdin = dup(tmpin);
	if (fdin != -2)
		return (fdin);
	else
		return (old_fd);
}

void	exec_cmd(t_session *s, t_cmd_tab *tb)
{
	int		tmpin;
	int		tmpout;
	int		fdin;
	int		change;

	change = 0;
	tmpin = dup(0);
	tmpout = dup(1);
	s->std_fd[0] = dup(tmpin);
	s->std_fd[1] = dup(tmpout);
	while (s->process_lst != NULL)
	{
		fdin = def_fdin(tmpin, s, change++, fdin);
		if (fdin == -1)
			perror("error");
		pipe_create(fdin, tmpout, s);
		run_command(s, tb);
		s->process_lst = s->process_lst->next;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
	close(s->std_fd[0]);
	close(s->std_fd[1]);
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
