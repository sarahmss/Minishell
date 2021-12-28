/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:31:18 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 22:01:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_bool	ft_pwd(t_process *p)
{
	char	wd[10000];
	int		argc;

	argc = 1;
	while (p->argv[argc])
		argc++;
	if (argc != 1)
	{
		ft_check_error(ENUMARG, "ENV: Invalid args", NULL);
		return (false);
	}
	if (!getcwd(wd, 10000))
	{
		ft_strcpy(wd, "pwd: not able to determine current working directory");
		ft_check_error(ECOMMAND, wd, NULL);
		return (false);
	}
	else
		printf("%s \n", wd);
	return (true);
}
