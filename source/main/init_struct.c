/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgana <morgana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:53:35 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/17 22:15:22 by morgana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_cmd_tab	*init_cmd_tab(t_session *session)
{
	t_cmd_tab	*table;

	table = (t_cmd_tab *)malloc(sizeof(t_cmd_tab));
	if (!table)
		ft_check_error(EALLOC, "Initing structure", table);
	table->session = session;
	table->cmd_line = NULL;
	table->cmd_splitted = NULL;
	table->piped_cmd = NULL;
	table->simple_cmd = NULL;
	return (table);
}

t_session	*init_session(char *envp[])
{
	t_session	*session;

	session = ft_calloc(1, sizeof(t_session));
	if (!session)
		ft_check_error(EALLOC, "INITIALIZING SESSION", NULL);
	session->env = load_env(envp);
	session->envp = envp;
	session->errcd = 0;
	session->stat = 0;
	session->child_envp = NULL;
	session->process_lst = NULL;
	return (session);
}
