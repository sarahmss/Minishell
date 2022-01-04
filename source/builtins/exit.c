/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:57:57 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/04 14:44:11 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	exit the shell, returning a status of n to the shell’s parent. If n is
	omitted, the exit status is that of the last command executed. Any trap on
	exit is executed before the shell terminates.
*/
void	ft_exit(t_cmd_tab *tb, t_session *s, t_process *p)
{
	char	**argv;
	int		argc;
	int		status;
	char	*arg;

	argc = 0;
	argv = p->argv;
	status = s->errcode;
	while (argv[argc + 1] != NULL)
		argc++;
	if (argc > 1)
		return ((void)ft_check_error(ENUMARG, "exit: invalid args", NULL));
	if (argc == 1)
	{
		arg = argv[1];
		argc = 0;
		while (arg[argc])
		{
			if ((!ft_isdigit(arg[argc])) && (arg[argc] != '-'))
				return ((void)ft_check_error(ENUMARG, "exit no num arg", NULL));
			argc++;
		}
		status = ft_atoi(argv[1]);
	}
	exit_shell(status, tb);
}
