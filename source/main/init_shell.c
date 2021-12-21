/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 18:35:37 by smodesto         ###   ########.fr       */
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
	session->e_size = session->env->count;
	session->envp = envp;
	repl(session);
	free_ht_tab(session->env);
	free (session);
	return (EXIT_SUCCESS);
}
