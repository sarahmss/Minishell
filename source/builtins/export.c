/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:19:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/26 16:16:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	export_no_args(t_ht_tab *table)
{
	int	i;
	int	total;

	i = 0;
	total = table->count;
	while (i < HT_SIZE_ENV && total)
	{
		if (table->items[i])
		{
			printf("declare -x");
			printf("%s=%s\n", table->items[i]->key, table->items[i]->value);
			total--;
		}
		i++;
	}
}

t_bool	ft_export(t_process *p, t_session *s)
{
	int	i;

	if (!p->argv[1])
		export_no_args(s->env);
	if (!ft_strchr(p->argv[1], '='))

	return (true);
}
