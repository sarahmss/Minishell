/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:50:38 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 11:33:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

// returns the current workind directory use mod == 0 unless in prompt funcition
char    *working_directory(int  mod)
{
    char    *cwd;
    char    *temp;

    if (mod == 0)
        return (getcwd(NULL, 0));
    temp = getcwd(NULL, 0);
    cwd = ft_strjoin(temp, "$");
    free(temp);
    return (cwd);
}

void    create_prompt(t_cmd_tab*table)
{
    char    *user;
    char    *prompt;
    char    *command_line;
    char    *cwd;
    
    user = ft_strjoin(getenv("USER"), ":");
    cwd = working_directory(1);
    prompt = ft_strjoin(user, cwd); 
    command_line = readline(prompt);
    if (strlen(command_line) != 0)
        add_history(command_line);
    table->cmd_splitted = ft_split(command_line, ' ');
    free(user);
    free(cwd);
    free(prompt);
    free(command_line);
}