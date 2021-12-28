/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:58:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 00:55:28 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	ft_env(t_session *s, t_ht_tab *table)
{
	int	i;
	int	total;
	int	argc;

	argc = 0;
	while (s->process_lst->argv[argc + 1])
		argc++;
	if (argc != 1)
		return (ft_check_error(ENUMARG, "ENV: Invalid args", NULL));
	i = 0;
	total = table->count;
	while (i < HT_SIZE_ENV && total)
	{
		if (table->items[i] && table->items[i]->is_env == true)
		{
			printf("%s=%s\n", table->items[i]->key, table->items[i]->value);
			total--;
		}
		i++;
	}
	return (0);
}
