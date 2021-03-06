/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:56:56 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/09 00:32:52 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_cmd_tab	*g_tb;

void	sig_doc(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		exit(130);
	}
	if (signal == SIGQUIT)
		return ;
}

/*
	CTRL+C: Redisplay prompt
		1. Move to a new line
		2. Regenerate the prompt on a newline
		3. Clear the previous text
	CTRL+\: do nothing

*/
void	redisplay_prompt(int signal)
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
	{
		session = g_tb->session;
		printf("\n");
		session->errcd = SINT;
		return ;
	}
	if (signal == SIGQUIT)
	{
		session = g_tb->session;
		printf("Quit (core dumped)\n");
		session->errcd = SQUIT;
		return ;
	}
}

void	no_empty_line(t_cmd_tab *tb)
{
	g_tb = tb;
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
}
