/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:51:20 by kde-oliv          #+#    #+#             */
/*   Updated: 2022/01/20 20:32:08 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	run_command(t_session *session, t_cmd_tab *tb)
{
	char	**envp;
	pid_t	pid;
	char	*full_path;

	if (tk_builtin(session->process_lst->command))
		return ((void)run_builtins(tb));
	envp = session->child_envp;
	full_path = get_fullpath(session, session->process_lst->command);
	if (full_path == NULL)
		return ;
	pid = fork();
	if (pid < 0)
		perror("error creating fork");
	else if (pid == 0)
	{
		session->errcd = execve(full_path, session->process_lst->argv, \
		envp);
		perror("error execve");
		return ;
	}
	waitpid(pid, &session->stat, 0);
	free (full_path);
	return ;
}

//eval multiples redirections output<<
static int	get_output_file(t_session *session)
{
	int		fdout;
	mode_t	mode;
	int 	i;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	while (session->process_lst->output_file[i])
	{
		if (session->process_lst->output_file[i]->flags == 0)
			fdout = open(session->process_lst->output_file[i]->path, \
		O_WRONLY | O_CREAT | O_TRUNC, mode);
		else
			fdout = open(session->process_lst->output_file[i]->path, \
		O_RDWR | O_APPEND );
		i++;
	}
	return (fdout);
}

static void	pipe_create(int fdin, int tmpout, t_session *session)
{
	int		fdout;
	int		fdpipe[2];

	dup2(fdin, 0);
	close(fdin);
	if (session->process_lst->next == NULL) // simple command
	{
		if (session->process_lst->output_file[0])
			fdout = get_output_file(session);
		else
			fdout = dup(tmpout);
	}
	else
	{
		fdout = get_output_file(session);
		if (pipe(fdpipe) < 0)
			ft_putstr_fd("error creating pipe", STDERR_FILENO);
		fdout = fdpipe[1];
		fdin = fdpipe[0];
	}
	dup2(fdout, 1);
	close(fdout);
	return ;
}

void	exec_cmd(t_session *session, t_cmd_tab *tb)
{
	int		tmpin;
	int		tmpout;
	int		fdin;

	tmpin = dup(0);
	tmpout = dup(1);
	if (session->process_lst->input_file[0])
		fdin = open(session->process_lst->input_file[0]->path, O_RDONLY);
	else
		fdin = dup(tmpin);
	if (fdin == -1)
	{
		perror("error:");
		return ;
	}
	while (session->process_lst != NULL)
	{
		pipe_create(fdin, tmpout, session);
		run_command(session, tb);
		session->process_lst = session->process_lst->next;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
}
