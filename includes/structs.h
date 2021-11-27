/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 12:19:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# define CLEAR "\033[H\033[J"
# define CAPACITY 50000
# define TOK_BUFSIZE 64
# define TOK_DELIM " \t\r\n\a"

// store the cmds that will be executed.
typedef struct s_cmd_tab
{
	char	*cmd_line;
	char	**cmd_splitted;
	char	*history;
	int		status;

}	t_cmd_tab;

#endif
