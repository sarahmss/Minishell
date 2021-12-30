/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:51:20 by kde-oliv          #+#    #+#             */
/*   Updated: 2021/12/30 13:41:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	run_command(t_session *session)
{
	char	**envp;
	int		ret;
	char	*full_path;

	envp = session->child_envp;
	ret = fork();
	if (ret < 0)
		perror("error creating fork");
	else if (ret == 0)
	{
		full_path = get_fullpath(session, session->process_lst->command);
		if (full_path == NULL)
			return ;
		session->errcode = execve(full_path, session->process_lst->argv, envp);
		perror("error execve");
		return ;
	}
	waitpid(ret, NULL, 0);
	return ;
}

static void	pipe_create(int fdin, int tmpout, t_session *session)
{
	int		fdout;
	int		fdpipe[2];
	mode_t	mode;

	dup2(fdin, 0);
	close(fdin);
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	if (session->process_lst->next == NULL)
	{
		if (session->process_lst->output_file[0])
			fdout = open(session->process_lst->output_file[0]->path, \
			O_WRONLY | O_CREAT | O_TRUNC, mode);
		else
			fdout = dup(tmpout);
	}
	else
	{
		if (pipe(fdpipe) < 0)
			ft_putstr_fd("error creating pipe", STDERR_FILENO);
		fdout = fdpipe[1];
		fdin = fdpipe[0];
	}
	dup2(fdout, 1);
	close(fdout);
	return ;
}

void	exec_cmd(t_session *session)
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
		run_command(session);
		session->process_lst = session->process_lst->next;
	}
	dup2(tmpin, 0);
	dup2(tmpout, 1);
	close(tmpin);
	close(tmpout);
}
