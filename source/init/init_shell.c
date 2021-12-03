/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/03 11:32:13 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	main(void)
{
	t_cmd_tab	*tb;

	while (1)
	{
		tb = init_cmd_tab();
		ft_read_line(tb);
		tokenizer(tb);
		before_living(tb);
	}
}
