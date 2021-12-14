/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:19:39 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/14 13:10:09 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# define HT_SIZE_ENV 1031
# include "./Minishell.h"

//	env_variables
char		*set_value(t_ht_tab *env, char *str, t_bool is_env);
void		split_var(char *str, char *var_split[]);

//	env_load
t_ht_tab	*load_env(char *envp[]);

void		env_expand_var(char **cmd_splitted, t_ht_tab *env);
char		*assign_value(char *str, t_ht_tab *env, int j);
#endif
