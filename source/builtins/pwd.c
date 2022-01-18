/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:31:18 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/18 09:57:04 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	ft_pwd(t_process *p)
{
	char	wd[100000];

	(void)p;
	if (!getcwd(wd, 100000))
	{
		ft_strcpy(wd, "pwd: not able to determine current working directory");
		return (ft_check_error(ECOMMAND, wd, NULL));
	}
	else
		printf("%s \n", wd);
	return (0);
}
