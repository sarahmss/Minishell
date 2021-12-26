/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 01:19:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	execute_root(t_session *session, t_cmd_tab *tb)
{
	char	**local_env;
	int		assign;

	assign = 0;
	local_env = session->process_lst->local_env;
	session->child_envp = env_local(local_env, session->envp, session->e_size);
	assign = env_assign(local_env, session->env);
	if (!assign && session->process_lst->next == NULL)
		root_simple_cmd(session, tb);
	/*
	else
		root_piped_cmd(session, tb);*/
	return (1);
}
