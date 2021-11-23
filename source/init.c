/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:53:35 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 11:55:12 by smodesto         ###   ########.fr       */
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

t_command_table *init_command_table()
{
    t_command_table *table;

    table = (t_command_table *)malloc(sizeof(t_command_table));
    if (!table)
		ft_check_error(-1, "Initing structure", table);
    table->command_splitted = NULL;
	table->history = NULL;
	init_shell();
	return (table);
}

/*
	free memory before living
*/
void    before_living(t_command_table *table)
{
	if (table->history != NULL)
		free(table->history);
    if (table->command_splitted != NULL)
        free_matrix(table->command_splitted);
    if (table)
       free(table);
}

/*
	-1: ERROR\n
	0: exit
	else:-ERRO msg
*/
void	ft_check_error(int err, char *msg, t_command_table *table)
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