/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:51:20 by kde-oliv          #+#    #+#             */
/*   Updated: 2022/01/25 13:37:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	run_command(t_session *s, t_cmd_tab *tb)
{
	char	**envp;
	pid_t	pid;
	char	*full_path;

	if (tk_builtin(s->process_lst->command))
		return ((void)run_builtins(tb));
	envp = s->child_envp;
	full_path = get_fullpath(s, s->process_lst->command);
	if (full_path == NULL)
		return ;
	pid = fork();
	if (pid < 0)
		perror("error creating fork");
	else if (pid == 0)
	{
		s->errcd = execve(full_path, s->process_lst->argv, \
		envp);
		perror("error execve");
		return ;
	}
	waitpid(pid, &s->stat, 0);
	free (full_path);
	return ;
}

/* eval multiples redirections output<< */
static int	get_output_file(t_session *s)
{
	int		fdout;
	mode_t	mode;
	int		i;

	i = 0;
	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	while (s->process_lst->output_file[i])
	{
		if (s->process_lst->output_file[i]->flags == 0)
			fdout = open(s->process_lst->output_file[i]->path, \
		O_WRONLY | O_CREAT | O_TRUNC, mode);
		else
			fdout = open(s->process_lst->output_file[i]->path, \
		O_RDWR | O_APPEND);
		i++;
	}
	return (fdout);
}

static void	pipe_create(int fdin, int tmpout, t_session *s)
{
	int		fdout;
	int		fdpipe[2];

	dup2(fdin, 0);
	close(fdin);
	if (s->process_lst->next == NULL)
	{
		if (s->process_lst->output_file[0])
			fdout = get_output_file(s);
		else
			fdout = dup(tmpout);
	}
	else
	{
		fdout = get_output_file(s);
		if (pipe(fdpipe) < 0)
			ft_putstr_fd("error creating pipe", STDERR_FILENO);
		fdout = fdpipe[1];
		fdin = fdpipe[0];
	}
	dup2(fdout, 1);
	close(fdout);
	return ;
}

int	def_fdin(int tmpin, t_session *s)
{
	int		fdin;
	t_file	*file;
	int		i;

	i = 0;
	while (s->process_lst->input_file[i])
		i++;
	file = s->process_lst->input_file[i];
	if (file && file->flags == 2)
		fdin = open(file->path, O_RDONLY);
	else if (file)
		fdin = redir(file->path);
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
	{
		perror("error:");
		return ;
	}
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
