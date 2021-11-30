/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 15:20:46 by smodesto         ###   ########.fr       */
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
# include <readline/readline.h>
# include <readline/history.h>

// init
t_cmd_tab		*init_cmd_tab(void);
void			before_living(t_cmd_tab *table);
void			ft_check_error(int err, char *msg, t_cmd_tab *table);

// cmd_line
void			ft_read_line(t_cmd_tab *tb);
char			*create_prompt(void);
char			*working_directory(int mod);

// Tokenizer
char			*ft_strtok(char *str, char delimiter);
char			**ft_split_cmd(char *line, char delimiter, t_cmd_tab *tab);
void			dq_cmd_tab(t_cmd_tab *tab, char **old, char c);
int				dq(char	*line, char c);

#endif
