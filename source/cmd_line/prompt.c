/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:43:14 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 16:43:17 by smodesto         ###   ########.fr       */
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
