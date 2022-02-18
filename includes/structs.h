/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morgana <morgana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/17 22:15:23 by morgana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CLEAR "\033[2J"
# define PURPLE "\001\e[0;35m\002"
# define BLUE "\001\e[0;37m:\002"

# include "hash_table.h"

//	parse
// flags [2: O_RDONLY |1: WRONLY CREAT APPEND| 0: WRONLY CREAT TRUNC ]
typedef struct s_file
{
	char				*path;
	int					flags;
	int					fd;
}						t_file;

typedef struct s_process
{
	char				*local_env[32];
	char				*command;
	char				*argv[64];
	t_file				*input_file[16];
	t_file				*output_file[16];
	struct s_process	*next;
	struct s_process	*prev;
}						t_process;

typedef enum e_index
{
	I_ARGV,
	I_ENV,
	I_IRED,
	I_ORED,
	I_SIZE
}						t_index;

// token
typedef enum e_type
{
	T_UNDEFINED,
	T_WORD,
	T_IREDIRECT,
	T_OREDIRECT,
	T_OAPPEND,
	T_IREADNOHISTORY,
	T_BUILTIN,
	T_SEMICOLON,
	T_PIPE,
}					t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

// shell
typedef struct s_session
{
	t_ht_tab	*env;
	t_process	*process_lst;
	char		**envp;
	char		**child_envp;
	int			errcd;
	int			stat;
}	t_session;

typedef struct s_cmd_tab
{
	t_session	*session;
	char		*cmd_line;
	char		**cmd_splitted;
	t_token		**piped_cmd;
	t_token		*simple_cmd;
}	t_cmd_tab;

#endif
