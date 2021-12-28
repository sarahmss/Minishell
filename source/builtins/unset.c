/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:59:42 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 00:58:11 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	ft_unset(t_ht_tab *env, t_process *p)
{
	int			i;
	t_ht_item	*current;

	i = 1;
	current = NULL;
	while (p->argv[i])
	{
		current = ht_search(env, p->argv[i]);
		if (current != NULL)
			ht_delete(env, p->argv[i]);
		else
			return (ft_check_error (ENUMARG, "unset, invalid args", NULL));
		i++;
	}
	return (true);
}
