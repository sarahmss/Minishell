/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_ut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 10:12:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	search for an intem in the hash table
*/
char	*ht_search(t_ht_tab *ht, char *key)
{
	int			index;
	t_ht_item	*item;
	t_linkdlst	*head;

	index = hash_function(key);
	item = ht->items[index];
	head = ht->overflow_buckets[index];
	while (item != NULL)
	{
		if (ft_strncmp(item->key, key, ft_strlen(key)) == 0)
			return (item->value);
		if (head == NULL)
			return (NULL);
		item = head->item;
		head = head->next;
	}
	return (NULL);
}
