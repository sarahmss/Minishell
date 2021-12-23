/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:57:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 21:16:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Exit the shell, returning a status of n to the shell’s parent. If n is
	omitted, the exit status is that of the last command executed. Any trap on
	EXIT is executed before the shell terminates.
*/
void	ft_exit(t_cmd_tab *tb, t_session *s, t_process *p)
{
	char	**argv;
	int		argc;
	int		status;
	char	*arg;

	argc = 0;
	argv = p->argv;
	status = s->status;
	while (argv[argc + 1] != NULL)
		argc++;
	if (argc > 1)
		ft_check_error(ENUMARG, "EXIT: TOO MANY ARGS", tb);
	if (argc == 1)
	{
		arg = argv[1];
		while (*arg)
		{
			if (!ft_isdigit(*arg++))
				ft_check_error(ENUMARG, "EXIT: NON NUMERICAL ARG", tb);
		}
		status = ft_atoi(argv[1]);
	}
	ft_check_error(status, "exit\n", tb);
}
