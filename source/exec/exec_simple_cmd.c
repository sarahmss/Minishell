/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:01:52 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 01:34:08 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	exec_simple_cmd(t_session *session)
{
	char	*command;
	char	*full_path;
	char	**argv;
	char	**envp;

	command = session->process_lst->command;
	if (is_executable(command) == true)
		full_path = command;
	else
		full_path = find_full_path(session->env, command);
	if (full_path == NULL)
	{
		session->status = ft_check_error(ENOFD, "command not found", NULL);
		return ;
	}
	argv = session->process_lst->argv;
	envp = session->child_envp;
	session->status = execve(full_path, argv, envp);
	if (session->status == -1)
	{
		perror("Could not execute execve");
		session->status = ft_check_error(ECMDNF, "command not found", NULL);
	}
	free (full_path);
	return ;
}

void	root_simple_cmd(t_session *session, t_cmd_tab *tb)
{
	pid_t	pid;
	int		status;

	if (tk_builtin(session->process_lst->command))
		run_builtins(tb, session, session->process_lst);
	else
	{
		pid = fork();
		if (pid < 0)
			ft_check_error(-1, "Failed forking child..", tb);
		else if (pid == 0)
			exec_simple_cmd(session);
		else
			waitpid(pid, &status, 0);
	}
}
