/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:01:52 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 18:31:07 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	exec_simple_cmd(t_session *session)
{
	char	*command;
	char	*full_path;
	char	**argv;
	char	**envp;

	command = session->jobs->process_lst->command;
	full_path = find_full_path(session->env, command);
	if (full_path == NULL)
		return ;
	argv = session->jobs->process_lst->argv;
	envp = session->child_envp;
	if (execve(full_path, argv, envp) == -1)
		perror("Could not execute execve");
	free (full_path);
}

void	fork_simple_cmd(t_session *session, t_cmd_tab *tb)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_check_error(ERRSYS, "Failed forking child..", tb);
		return ;
	}
	else if (pid == 0)
		exec_simple_cmd(session);
	else
	{
		wait (NULL);
		return ;
	}
}
