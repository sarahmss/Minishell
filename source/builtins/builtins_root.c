/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_root.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:57:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/25 18:45:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_bool	run_builtins(t_cmd_tab *tb, t_session *s, t_process *p)
{
	char	*command;
	t_bool	ret;

	ret = false;
	command = p->command;
	if (ft_strcmp("echo", command))
		ret = ft_echo(p->argv);
	if (ft_strcmp("exit", command))
		ft_exit(tb, s, p);
	if (ft_strcmp("env", command))
		ret = ft_env(s->env);
/*	if (ft_strcmp("unset", command))
		ret = ft_unset(s);
	if (ft_strcmp("export", command))
		ret = ft_export(s);
	if (ft_strcmp("cd", command))
		ret = ft_cd(s);
	if (ft_strcmp("pwd", command))
		ret = ft_pwd(s);*/
	return (ret);
}
