/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/25 18:06:39 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "./structs.h"
# include "./hash_table.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>

//prompt 
void            create_prompt(t_cmd_tab *table);
char            *working_directory(int  mod);

// init
t_cmd_tab *init_cmd_tab();
void             before_living(t_cmd_tab *table);
void	         ft_check_error(int err, char *msg, t_cmd_tab *table);
#endif
