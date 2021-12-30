/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:19:59 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 00:58:19 by smodesto         ###   ########.fr       */
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
		if (table->items[i] && table->items[i]->is_env == true)
		{
			printf("declare -x ");
			printf("%s=%s\n", table->items[i]->key, table->items[i]->value);
			total--;
		}
		i++;
	}
}

int	ft_export(t_process *p, t_session *s)
{
	int	i;

	i = 1;
	if (!p->argv[1])
		export_no_args(s->env);
	while (p->argv[i])
	{
		if (ft_strchr(p->argv[i], '='))
			set_value(s->env, p->argv[i], 1);
		else
			return (ft_check_error (ENUMARG, "export, invalid args", NULL));
		i++;
	}
	return (0);
}
