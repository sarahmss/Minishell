/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:53:35 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/03 11:22:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_cmd_tab	*init_cmd_tab(void)
{
	t_cmd_tab	*table;

	table = (t_cmd_tab *)malloc(sizeof(t_cmd_tab));
	if (!table)
		ft_check_error(-1, "Initing structure", table);
	table->cmd_line = NULL;
	table->cmd_splitted = NULL;
	table->history = NULL;
	table->status = 0;
	table->piped_cmd = NULL;
	table->simple_cmd = NULL;
	return (table);
}

/*
	free memory before living
*/
void	before_living(t_cmd_tab *table)
{
	if (table->cmd_line != NULL)
		free(table->cmd_line);
	if (table->history != NULL)
		free(table->history);
	if (table->cmd_splitted != NULL)
		free_matrix(table->cmd_splitted);
	if (table->simple_cmd)
		tk_free_lst(table->simple_cmd);
	if (table->piped_cmd)
	{
		tk_free_lst(table->piped_cmd[0]);
		tk_free_lst(table->piped_cmd[1]);
	}
	if (table)
		free(table);
}

/*
	-1: ERROR\n
	0: exit
	else:-ERRO msg
*/
void	ft_check_error(int err, char *msg, t_cmd_tab *table)
{
	before_living(table);
	if (err == -1)
	{
		write(2, "Error\n", 6);
		exit (0);
	}
	if (err == 0)
		exit (0);
	else
	{
		ft_printf("-ERRO: %s", msg);
		exit (0);
	}
}
