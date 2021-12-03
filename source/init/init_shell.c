/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:53:26 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/02 20:58:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	main(void)
{
	t_cmd_tab	*tb;

	tb = init_cmd_tab();
	while (1)
	{
		ft_read_line(tb);
		tokenizer(tb);
	}
}
