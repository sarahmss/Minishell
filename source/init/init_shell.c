/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/18 13:45:10 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_session	*g_session;

/*Read–eval–print loop*/
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
	if (argc != 1)
		ft_check_error(-1, "USE MOOD: ./minishell", NULL);
	session = ft_calloc(1, sizeof(t_session));
	if (!session)
		ft_check_error(-1, "INITIALIZING SESSION", NULL);
	g_session = session;
	session->env = load_env(envp);
	repl(session);
	return (EXIT_SUCCESS);
}
