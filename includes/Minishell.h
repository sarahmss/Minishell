/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:56:26 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/03 22:08:08 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include "../libraries/libft/libft.h"
# include "./structs.h"
# include "./errcode.h"
# include "./hash_table.h"
# include "./token.h"
# include "./environment.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

// init
t_session		*init_session(char *envp[]);
t_cmd_tab		*init_cmd_tab(t_session *session);
void			greetings(void);
void			before_living(t_cmd_tab *table);
int				ft_check_error(t_errcode code, char *msg, t_cmd_tab *table);
void			repl(t_session *session);
void			free_session(t_session *session);
void			exit_shell(t_errcode code, t_cmd_tab *table);


// cmd_line
void			ft_read_line(t_cmd_tab *tb);
char			*create_prompt(void);
char			*working_directory(int mod);

// parse
void			push_process(t_process **lst, t_process *new_p);
t_process		*parser(t_cmd_tab *tb);
t_process		*parse_command(t_token **tokens);

// execute
int				execute_root(t_session *session, t_cmd_tab *tb);
char			*find_full_path(t_ht_tab *env, char *command);
char			*get_fullpath(t_session *session, char *command);
void			exec_cmd(t_session *session);
t_bool			is_executable(char *path_cmd);

// builtins
int				run_builtins(t_cmd_tab *tb, t_session *s, t_process *p);
int				ft_echo(char **argv);
void			ft_exit(t_cmd_tab *tb, t_session *s, t_process *p);
int				ft_env(t_session *s, t_ht_tab *table);
int				ft_export(t_process *p, t_session *s);
int				ft_unset(t_ht_tab *env, t_process *p);
int				ft_cd(t_process *p, t_ht_tab *env);
int				ft_pwd(t_process *p);

// signals
void			empty_line(void);
void			no_empty_line(t_cmd_tab *tb);
#endif
