/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:53:35 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 11:32:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

// Greeting shell during startup
static void init_shell()
{
	char* username;

    printf(CLEAR);
    printf("\n\n\n\n******************"
        "************************");
    printf("\n\n\n\t****MINISHELL****");
    printf("\n\n\t-USE AT YOUR OWN RISK-");
    printf("\n\n\n\n*******************"
        "***********************");
    username = getenv("USER");
    printf("\n\n\nUSER is: @%s", username);
    printf("\n");
    sleep(3);
    printf(CLEAR);
}

t_cmd_tab *init_command_table()
{
    t_cmd_tab *table;

    table = (t_cmd_tab *)malloc(sizeof(t_cmd_tab));
    if (!table)
		ft_check_error(-1, "Initing structure", table);
    table->cmd_splitted = NULL;
	table->history = NULL;
	init_shell();
	return (table);
}

/*
	free memory before living
*/
void    before_living(t_cmd_tab *table)
{
	if (table->history != NULL)
		free(table->history);
    if (table->cmd_splitted != NULL)
        free_matrix(table->cmd_splitted);
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