/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 01:20:04 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_session	*session;

	(void)argv;
	if (argc != 1)
		ft_check_error(EUSAGE, "USE MOOD: ./minishell", NULL);
	session = ft_calloc(1, sizeof(t_session));
	if (!session)
		ft_check_error(EALLOC, "INITIALIZING SESSION", NULL);
	session->env = load_env(envp);
	session->envp = envp;
	session->e_size = ft_arraylen((void **)session->envp);
	session->status = 0;
	repl(session);
	free_session(session);
	return (EXIT_SUCCESS);
}
