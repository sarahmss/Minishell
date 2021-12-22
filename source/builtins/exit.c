/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:57:57 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 14:56:20 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Exit the shell, returning a status of n to the shell’s parent. If n is
	omitted, the exit status is that of the last command executed. Any trap on
	EXIT is executed before the shell terminates.
*/
t_bool	ft_exit(t_cmd_tab *tb, t_session *s, t_process *p)
{
	char	**argv;
	int		argc;
	int		status;

	argc = 0;
	argv = p->argv;
	status = s->status;
	while (argv[argc] != NULL)
		argc++;
	if (argc > 1)
		ft_check_error(ENUMARG, "EXIT: too many args", tb);
	if (argc == 1)
	{
		while (*argv[1])
			if (!ft_isdigit(*argv[1]++))
				ft_check_error(ENUMARG, "EXIT: non numerial arg", tb);
		status = ft_atoi(argv[1]);
	}
	printf("exit\n");
	before_living(tb);
	exit(status);
}
