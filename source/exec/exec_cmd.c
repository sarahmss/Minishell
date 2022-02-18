/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 08:51:20 by kde-oliv          #+#    #+#             */
/*   Updated: 2022/02/17 22:52:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	valid_input(t_session *s)
{
	int			i;
	static int	invalid_fd;

	i = -1;
	if (invalid_fd > 0)
	{
		invalid_fd = 0;
		return (0);
	}
	if (s->process_lst->input_file[i + 1])
	{
		while (s->process_lst->input_file[i + 1])
			i++;
		if (s->process_lst->input_file[i]->fd < 0)
		{
			invalid_fd++;
			return (0);
		}
	}
	return (1);
}

void	run_command(t_session *s, t_cmd_tab *tb)
{
	char	**envp;
	pid_t	pid;
	char	*full_path;

	if (tk_builtin(s->process_lst->command))
		return ((void)run_builtins(tb));
	if (!valid_input(s))
		return ;
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

/* eval multiples redirections output >> */
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
		O_WRONLY | O_CREAT | O_APPEND, mode);
		i++;
	}
	return (fdout);
}

static int	pipe_simple_cmd(int tmpout, t_session *s)
{
	int		fdout;

	if (s->process_lst->output_file[0])
		fdout = get_output_file(s);
	else
		fdout = dup(tmpout);
	return (fdout);
}

void	pipe_create(int fdin, int tmpout, t_session *s)
{
	int		fdout;
	int		fdpipe[2];

	if (fdin > 0)
	{
		dup2(fdin, 0);
		close(fdin);
	}
	if (s->process_lst->next == NULL)
		fdout = pipe_simple_cmd(tmpout, s);
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
