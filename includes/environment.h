/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:19:39 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 01:07:11 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# define HT_SIZE_ENV 1031
# include "./Minishell.h"

//	env_variables
char		*set_value(t_ht_tab *env, char *str);
void		split_var(char *str, char *var_split[]);

//	env_load
t_ht_tab	*load_env(char *envp[]);
char		**env_local(char **local_envp, char **envp, int envp_size);
int			env_assign(char *envp[], t_ht_tab *env);

void		env_expand_var(char **cmd_splitted, t_ht_tab *env);
char		*assign_value(char *str, t_ht_tab *env, int j);
#endif
