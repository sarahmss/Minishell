/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:31:18 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 00:58:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	ft_pwd(t_process *p)
{
	char	wd[10000];
	int		argc;

	argc = 1;
	while (p->argv[argc])
		argc++;
	if (argc != 1)
		return (ft_check_error(ENUMARG, "ENV: Invalid args", NULL));
	if (!getcwd(wd, 10000))
	{
		ft_strcpy(wd, "pwd: not able to determine current working directory");
		return (ft_check_error(ECOMMAND, wd, NULL));
	}
	else
		printf("%s \n", wd);
	return (0);
}
