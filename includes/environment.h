/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:19:39 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 01:37:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# define HT_SIZE_ENV 10000
# include "./Minishell.h"

//	env_variables
t_ht_item	*set_value(t_ht_tab *env, char *str, int mood);
void		split_var(char *str, char *var_split[]);

//	env_load
t_ht_tab	*load_env(char *envp[]);
char		**env_local(t_ht_tab *env);
int			env_assign(char *envp[], t_ht_tab *env);

void		env_expand_var(char **cmd_splitted, t_ht_tab *env, int status);
char		*assign_value(char *str, t_ht_tab *env, int j);
#endif
