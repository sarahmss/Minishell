/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:50:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/08 19:16:01 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Greeting shell during startup
*/
static void	init_shell(void)
{
	char	*username;

	printf(CLEAR);
	printf("\n\n\n\n******************"
		"************************");
	printf("\n\n\n\t****MINISHELL****");
	printf("\n\n\t-USE AT YOUR OWN RISK-");
	printf("\n\n\n\n*******************"
		"***********************");
	username = getenv("USER");
	printf("\n\n\nUSER is: @%s", username);
	printf("\n");
	sleep(3);
	printf(CLEAR);
}

/*
	returns the current working directory use mod == 0 unless in prompt function
*/
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
	init_shell();
	prompt = ft_strjoin(user, cwd);
	free(user);
	free(cwd);
	return (prompt);
}
