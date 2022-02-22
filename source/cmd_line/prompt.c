/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:43:14 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/22 14:24:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	returns the current working directory use mood == 0 unless in prmt function
*/
char	*working_directory(int mood)
{
	char	*cwd;
	char	*temp;

	if (mood == 0)
		return (getcwd(NULL, 0));
	temp = getcwd(NULL, 0);
	cwd = ft_join_var(3, "\001\e[0;36m\002", temp, "\001\e[0;37m\002$ ");
	free(temp);
	return (cwd);
}

char	*create_prompt(void)
{
	char	*prmpt;
	char	*cwd;

	cwd = working_directory(1);
	prmpt = ft_join_var(4, "✨🐚✨", PURPLE, getenv("USER"), cwd);
	free(cwd);
	return (prmpt);
}
