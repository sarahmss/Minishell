/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:56 by smodesto          #+#    #+#             */
/*   Updated: 2022/03/01 23:26:20 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	run_builtins(t_cmd_tab *tb)
{
	char		*command;
	t_session	*s;
	t_process	*p;

	s = tb->session;
	p = tb->session->process_lst;
	command = p->command;
	if (ft_strcmp("echo", command))
		s->errcd = ft_echo(p->argv);
	if (ft_strcmp("exit", command))
		s->errcd = ft_exit(tb, s, p);
	if (ft_strcmp("env", command))
		s->errcd = ft_env(s, s->env);
	if (ft_strcmp("export", command))
		s->errcd = ft_export(p, s);
	if (ft_strcmp("unset", command))
		s->errcd = ft_unset(s->env, s->process_lst);
	if (ft_strcmp("pwd", command))
		s->errcd = ft_pwd(s->process_lst);
	if (ft_strcmp("cd", command))
		s->errcd = ft_cd(s->env, s->process_lst->argv);
	s->stat = 0;
	if (s->errcd)
		s->stat = 1;
	return (s->errcd);
}
