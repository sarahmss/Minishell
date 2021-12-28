/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prmt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:50:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 15:39:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	returns the current working directory use mod == 0 unless in prmt function
*/
char	*working_directory(int mod)
{
	char	*cwd;
	char	*temp;

	if (mod == 0)
		return (getcwd(NULL, 0));
	temp = getcwd(NULL, 0);
	cwd = ft_join_var(3, "\e[0;36m", temp, "\e[0;37m$ ");
	free(temp);
	return (cwd);
}

char	*create_prompt(void)
{
	char	*prmpt;
	char	*cwd;

	cwd = working_directory(1);
	prmpt = ft_join_var(4, "✨🐚✨\e[0;35m", getenv("USER"), "\e[0;37m:", cwd);
	free(cwd);
	return (prmpt);
}
