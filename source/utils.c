/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:46:52 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/19 09:50:06 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

// print current directory
void    printDir()
{
    char    cwd[1024];
    
    getcwd(cwd, sizeof(cwd));
    printf("\n%s > ", cwd);
}

char    *read_line