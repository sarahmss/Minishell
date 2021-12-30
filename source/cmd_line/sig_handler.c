/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 12:56:56 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 13:37:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

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
	if (signal == SIGINT)
		printf ("\n");
	if (signal == SQUIT)
		return ;
}

void	no_empty_line(t_cmd_tab *tb)
{
	signal(SIGINT, sig_handler);
	if (!signal(SIGQUIT, sig_handler))
		ft_check_error(SIGEXIT, "CTRL + \\", tb);
}
