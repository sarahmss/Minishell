/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:01:52 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/25 18:04:43 by smodesto         ###   ########.fr       */
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
	full_path = find_full_path(session->env, command);
	if (full_path == NULL)
		return ;
	argv = session->process_lst->argv;
	envp = session->child_envp;
	if (execve(full_path, argv, envp) == -1)
		perror("Could not execute execve");
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
			wait(&status);
	}
}
