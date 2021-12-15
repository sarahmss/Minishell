/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/14 21:19:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CLEAR "\033[H\033[J"
# include "hash_table.h"

typedef enum e_bool
{
	true,
	false
}					t_bool;

typedef struct s_variable
{
	char		*value;
	t_bool		env;
}				t_variable;

typedef struct s_session
{
	t_ht_tab	*env;
	char		**envp;
	size_t		envp_size;
}	t_session;

typedef enum e_type
{
	T_UNDEFINED,
	T_WORD,
	T_SEPARATOR,
	T_IREDIRECT,
	T_OREDIRECT,
	T_OAPPEND,
	T_IREADNOHISTORY,
	T_BUILTIN
}					t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

typedef struct s_cmd_tab
{
	t_session	*session;
	char		*cmd_line;
	char		**cmd_splitted;
	char		*history;
	t_token		**piped_cmd;
	t_token		*simple_cmd;
}	t_cmd_tab;

#endif
