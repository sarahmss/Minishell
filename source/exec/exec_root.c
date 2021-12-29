/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 10:54:32 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/29 11:17:30 by kde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	execute_root(t_session *session)
{
	char	**local_env;
	int		assign;

	assign = 0;
	local_env = session->process_lst->local_env;
	session->child_envp = env_local(local_env, session->envp, session->e_size);
	assign = env_assign(local_env, session->env);
	exec_cmd(session);
	return (1);
}
