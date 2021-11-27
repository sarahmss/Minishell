/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:50:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 11:39:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

// returns the current workind directory use mod == 0 unless in prompt funcition
char	*working_directory(int mod)
{
	char	*cwd;
	char	*temp;

	if (mod == 0)
		return (getcwd(NULL, 0));
	temp = getcwd(NULL, 0);
	cwd = ft_strjoin(temp, "$");
	free(temp);
	return (cwd);
}

char	*create_prompt(void)
{
	char	*user;
	char	*prompt;
	char	*cwd;

	user = ft_strjoin(getenv("USER"), ":");
	cwd = working_directory(1);
	prompt = ft_strjoin(user, cwd);
	free(user);
	free(cwd);
	return (prompt);
}

