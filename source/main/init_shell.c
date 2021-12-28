/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 18:43:47 by smodesto         ###   ########.fr       */
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
	repl(session);
	free_session(session);
	return (EXIT_SUCCESS);
}
