/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/29 11:17:30 by kde-oliv         ###   ########.fr       */
=======
/*   Updated: 2021/12/28 13:25:08 by smodesto         ###   ########.fr       */
>>>>>>> main
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	execute_root(t_session *session)
{
	char	**local_env;
	int		assign;

	assign = 0;
	local_env = session->process_lst->local_env;
	assign = env_assign(local_env, session->env);
<<<<<<< HEAD
	exec_cmd(session);
=======
	if (session->child_envp != NULL)
		free_matrix(session->child_envp);
	session->child_envp = env_local(session->env);
	if (!assign && session->process_lst->next == NULL)
		root_simple_cmd(session, tb);
	/*
	else
		root_piped_cmd(session, tb);*/
>>>>>>> main
	return (1);
}
