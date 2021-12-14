/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/14 13:14:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_session	*g_session;

void	repl(t_session	*session)
{
	t_cmd_tab	*tb;

	while (1)
	{
		tb = init_cmd_tab(session);
		ft_read_line(tb);
		tokenizer(tb);
		before_living(tb);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_session	*session;

	(void)argv;
	session = ft_calloc(1, sizeof(*session));
	if (!session)
		ft_check_error(-1, "INITIALIZING SESSION", NULL);
	g_session = session;
	if (argc != 1)
		ft_check_error(-1, "USE MOOD: ./minishell", NULL);
	session->env = load_env(envp);
	repl(session);
	return (EXIT_SUCCESS);
}
