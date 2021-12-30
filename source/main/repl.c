/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-oliv <kde-oliv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:33:48 by smodesto          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/12/29 14:14:31 by kde-oliv         ###   ########.fr       */
=======
/*   Updated: 2021/12/28 00:18:02 by smodesto         ###   ########.fr       */
>>>>>>> main
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
		if (session->status == 0)
			tokenizer(tb);
		if (session->status == 0 && !(token_error(tb)))
		{
			session->process_lst = parser(tb);
			execute_root(session);
		}
		before_living(tb);
	}
}
