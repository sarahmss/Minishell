/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 10:40:26 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

unsigned long	hash_function(char *str)
{
	unsigned long	hash;
	int				j;

	hash = 0;
	j = 0;
	while (str[j])
	{
		hash += str[j];
		j++;
	}
	return (hash % CAPACITY);
}

t_ht_item	*create_item(char *key, char *value, t_cmd_tab *table)
{
	t_ht_item	*item;

	item = (t_ht_item *)malloc(sizeof(t_ht_item));
	if (!item)
		ft_check_error(1, "CREATING ITEM", table);
	item->key = ft_strdup(key);
	item->value = ft_strdup(value);
	return (item);
}

t_ht_tab	*create_table(int size, t_cmd_tab *table)
{
	t_ht_tab	*ht_tab;
	int			i;

	i = 0;
	ht_tab = (t_ht_tab *)malloc(sizeof(t_ht_tab));
	if (!ht_tab)
		ft_check_error(1, "CREATING TABLE", table);
	ht_tab->size = size;
	ht_tab->count = 0;
	ht_tab->items = (t_ht_item **)ft_calloc(size, (sizeof(t_ht_item *)));
	while (i < size)
	{
		ht_tab->items[i] = NULL;
		i++;
	}
	ht_tab->overflow_buckets = create_overflow_buckets(ht_tab, table);
	return (ht_tab);
}

void	free_ht_item(t_ht_item *ht_item)
{
	free(ht_item->key);
	free(ht_item->value);
	free(ht_item);
}

void	free_ht_tab(t_ht_tab *ht_tab)
{
	int			i;
	t_ht_item	*item;

	i = 0;
	while (i < ht_tab->size)
	{
		item = ht_tab->items[i];
		if (item != NULL)
			free_ht_item(item);
		i++;
	}
	free_overflow_buckets(ht_tab);
	free(ht_tab->items);
	free(ht_tab);
}
