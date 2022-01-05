/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:33:48 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/04 20:47:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*Read–eval–print loop*/
void	repl(t_session	*session)
{
	t_cmd_tab	*tb;

	while (1)
	{
		tb = init_cmd_tab(session);
		ft_read_line(tb);
		if (session->errcd == 0)
			tokenizer(tb);
		if (session->errcd == 0 && !(token_error(tb)))
		{
			session->process_lst = parser(tb);
			execute_root(session, tb);
		}
		before_living(tb);
	}
}
