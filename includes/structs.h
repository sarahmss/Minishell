/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/03 10:58:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CLEAR "\033[H\033[J"
# define CAPACITY 50000

typedef enum e_type
{
	T_UNDEFINED,
	T_WORD,
	T_SEPARATOR,
	T_PIPE,
	T_END_OF_LINE,
	T_IREDIRECT,
	T_OREDIRECT,
	T_OAPPEND
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
