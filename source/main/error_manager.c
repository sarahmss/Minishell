/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:35:04 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/04 15:19:18 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	errmsg(char *str, int code)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	if (code)
		exit (code);
}

void	exit_shell(t_errcode code, t_cmd_tab *table)
{
	t_session	*session;

	session = NULL;
	if (table != NULL)
	{
		session = table->session;
		before_living(table);
	}
	if (session)
		free_session(session);
	exit (code);
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
	if (table != NULL)
		before_living(table);
	ft_putstr_fd("minishell- ", STDERR_FILENO);
	if ((int)code == -1 || code == EALLOC || code == EUSAGE)
		errmsg(msg, code);
	else if (code > 0)
	{
		errmsg(msg, 0);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	return (code);
}
