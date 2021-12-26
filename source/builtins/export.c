/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:19:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 00:41:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	export_no_args(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (envp[i])
			printf("declare -x %s\n", envp[i]);
		i++;
	}
	return (true);
}

t_bool	ft_export(t_process *p, char *envp[])
{
	int	i;

	if (!p->argv[1])
		export_no_args(envp);
	if (!ft_strchr(p->argv[1], '='))
		
	return (true);
}
