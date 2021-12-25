/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:58:11 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/25 18:28:55 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

t_bool	ft_env(t_ht_tab *table)
{
	int	i;
	int	total;

	i = 0;
	total = table->count;
	while (i < HT_SIZE_ENV && total)
	{
		if (table->items[i])
		{
			printf("%s=%s\n", table->items[i]->key, table->items[i]->value);
			total--;
		}
		i++;
	}
	return (true);
}
