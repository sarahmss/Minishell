/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greetings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 02:58:28 by coder             #+#    #+#             */
/*   Updated: 2021/12/28 15:53:59 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	Greeting shell during startup
*/

void	greetings(void)
{
	char	*username;

	printf(CLEAR);
	printf("\e[0;35m");
	printf("┌─┐┌─┐  ┌┐ ┌─┐┌─┐┬ ┬┌┬┐┬┌─┐┬ ┬┬    ┌─┐┌─┐  ┌─┐  ┌─┐┬ ┬┌─┐┬  ┬\n");
	printf("├─┤└─┐  ├┴┐├┤ ├─┤│ │ │ │├┤ │ ││    ├─┤└─┐  ├─┤  └─┐├─┤├┤ │  │\n");
	printf("┴ ┴└─┘  └─┘└─┘┴ ┴└─┘ ┴ ┴└  └─┘┴─┘  ┴ ┴└─┘  ┴ ┴  └─┘┴ ┴└─┘┴─┘┴─┘\n");
	printf("\e[0;36m");
	print_shell();
	printf("\e[0;37m");
	username = getenv("USER");
	printf("\n\n\nWelcome: @%s", username);
	printf("\n");
	sleep(2);
	printf(CLEAR);
}
