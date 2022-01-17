/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/16 19:02:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_session	*session;

	(void)argv;
	if (argc != 1)
		ft_check_error(EUSAGE, "USE MOOD: ./minishell", NULL);
	session = init_session(envp);
	greetings();
	repl(session);
	free_session(session);
	return (EXIT_SUCCESS);
}
