/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 01:00:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	run_builtins(t_cmd_tab *tb, t_session *s, t_process *p)
{
	char	*command;

	command = p->command;
	if (ft_strcmp("echo", command))
		s->status = ft_echo(p->argv);
	if (ft_strcmp("exit", command))
		ft_exit(tb, s, p);
	if (ft_strcmp("env", command))
		s->status = ft_env(s, s->env);
	if (ft_strcmp("export", command))
		s->status = ft_export(p, s);
	if (ft_strcmp("unset", command))
		s->status = ft_unset(s->env, s->process_lst);
	if (ft_strcmp("pwd", command))
		s->status = ft_pwd(s->process_lst);
	if (ft_strcmp("cd", command))
		s->status = ft_cd(s->process_lst, s->env);
	return (s->status);
}
