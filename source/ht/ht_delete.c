/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 10:12:52 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 19:58:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	sup(t_linkdlst *c, t_linkdlst *p, t_linkdlst *buck, t_linkdlst *h)
{
	p->next = c->next;
	c->next = NULL;
	ft_free_list(c);
	*buck = *h;
	return ;
}

static void	search_to_del(t_ht_tab *ht, t_linkdlst *head, char *key, int index)
{
	t_linkdlst	*curr;
	t_linkdlst	*prev;

	curr = head;
	prev = NULL;
	while (curr)
	{
		if (ft_strncmp(curr->item->key, key, ft_strlen(key)) == 0)
		{
			if (prev == NULL)
			{
				ft_free_list(head);
				ht->overflow_buckets[index] = NULL;
				return ;
			}
			else
				return (sup(curr, prev, ht->overflow_buckets[index], head));
		}
		curr = curr->next;
		prev = curr;
	}
}

/*
	No collision chain. Remove the item and set table index to NULL
 */
static void	no_colis(t_ht_tab *ht, t_ht_item *item, int index)
{
	ht->items[index] = NULL;
	free(item->key);
	free(item->value);
	free(item);
	ht->count--;
	return ;
}

/*
	Remove this item and set the head of the list as the new item
*/
static void	colision(t_ht_tab *ht, t_linkdlst *head, int index)
{
	t_linkdlst	*node;
	t_ht_item	*item;

	item = ht->items[index];
	free_ht_item(item);
	node = head;
	head = head->next;
	node->next = NULL;
	ht->items[index] = create_item(node->item->key, node->item->value);
	ft_free_list(node);
	ht->overflow_buckets[index] = head;
}

/*
	delete an intem in the hash table
*/
void	ht_delete(t_ht_tab *ht, char *key)
{
	int			index;
	t_ht_item	*item;
	t_linkdlst	*head;

	index = hash_function(key);
	item = ht->items[index];
	head = ht->overflow_buckets[index];
	if (item == NULL)
		return ;
	else
	{
		if (head == NULL && ft_strncmp(item->key, key, ft_strlen(key)) == 0)
			return (no_colis(ht, item, index));
		else if (head != NULL)
		{
			if (ft_strncmp(item->key, key, ft_strlen(key)) == 0)
				return (colision(ht, head, index));
			search_to_del(ht, head, key, index);
		}
	}
}
