/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:56:56 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/12 22:24:34 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_cmd_tab	*g_tb;

/*
	CTRL+C: Redisplay prompt
		1. Move to a new line
		2. Regenerate the prompt on a newline
		3. Clear the previous text
	CTRL+\: do nothing

*/
static void	redisplay_prompt(int signal)
{
	(void)signal;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/*
	Passing SIG_IGN as handler ignores a given signal.
*/
void	empty_line(void)
{
	signal(SIGINT, redisplay_prompt);
	signal(SIGQUIT, SIG_IGN);
}

static void	sig_handler(int signal)
{
	t_session	*session;

	if (signal == SIGINT)
		printf ("\n");
	if (signal == SIGQUIT)
	{
		session = NULL;
		if (g_tb != NULL)
		{
			session = g_tb->session;
			before_living(g_tb);
		}
		if (session)
			free_session(session);
		printf("Quit (core dumped)\n");
		exit (SQUIT);
	}
}

void	no_empty_line(t_cmd_tab *tb)
{
	g_tb = tb;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
