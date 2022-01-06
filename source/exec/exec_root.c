/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/04 20:49:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

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
<<<<<<< HEAD
	if (!assign && tk_builtin(session->process_lst->command))
		run_builtins(tb, session, session->process_lst);
	else if (!assign)
	{
		process_head = session->process_lst;
		exec_cmd(session);
		session->process_lst = process_head;
	}
=======
	if (!assign)
		exec_cmd(session, tb);
>>>>>>> b5cb4982d321cfcd478ecbee2bd5e6322bda0b99
	return (1);
}
