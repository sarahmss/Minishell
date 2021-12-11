/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/10 22:52:45 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	search for an intem in the hash table
		NULL if not found
*/
void	*ht_search(t_ht_tab *ht, char *key)
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
