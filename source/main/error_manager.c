/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:35:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 21:17:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	errmsg(char *str)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
}

/*
	exit when code == -1
	else select table arg == NULL, the error msg wil be printed and the shell
	must continue going
		- Shell language syntax error -----------------------> Shall exit
		- Utility syntax error (option or operand error)-----> Shall not exit
		- Redirection error ---------------------------------> Shall not exit
		- Variable assignment error -------------------------> Shall not exit
		- Expansion error -----------------------------------> Shall exit
		- Command not found ---------------------------------> Shall exit
		If a command is not found, the exit status shall be 127
		If the command name is found, but it is not an executable utility, the
		exit status shall be 126.
		If a command fails during word expansion or redirection, its exit
		status shall be greater than zero.
*/
int	ft_check_error(t_errcode code, char *msg, t_cmd_tab *table)
{
	t_session	*session;

	session = table->session;
	if (table != NULL)
		before_living(table);
	if (code == SIGEXIT || ft_strcmp(msg, "exit\n"))
	{
		free_session(session);
		exit (0);
	}
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	if ((int)code == -1 || code == EALLOC || code == EUSAGE)
	{
		errmsg(msg);
		exit (code);
	}
	else if (code > 0)
	{
		if (msg)
			errmsg(msg);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	return (code);
}
