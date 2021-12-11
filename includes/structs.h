/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/10 22:57:19 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CLEAR "\033[H\033[J"
# include "hash_table.h"

typedef int bool;
#define true 1
#define false 0

typedef struct	s_variable
{
	char		*value;
	bool		env;
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
	T_WORD$,
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

// store the cmds that will be executed.
typedef struct s_cmd_tab
{
	char	*cmd_line;
	char	**cmd_splitted;
	char	*history;
	int		status;
	t_token	**piped_cmd;
	t_token	*simple_cmd;
}	t_cmd_tab;

#endif
