/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdoubly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:58:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 10:06:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
Creates a new element at a doubly linked list and storage item in it
*/
t_linkdlst	*ft_get_new_node(t_ht_item *item)
{
	t_linkdlst	*new_node;

	new_node = (t_linkdlst *)malloc(sizeof(t_linkdlst));
	if (!new_node)
		return (NULL);
	new_node->item = item;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

/*
Insert a new element at the top of a doubly linked list
*/
t_linkdlst	*ft_insert_at_head(t_ht_item *item, t_linkdlst *head)
{
	t_linkdlst	*new_node;

	new_node = ft_get_new_node(item);
	if (head == NULL)
		head = new_node;
	else
	{
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
	return (new_node);
}

/*
	Delete a node del in the list
*/
t_ht_item	*node_del(t_linkdlst **head, t_linkdlst *del)
{
	t_ht_item	*item;

	item = NULL;
	if (*head == NULL || del == NULL)
		return (NULL);
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	ft_memcpy(item, del->item, sizeof(t_ht_item));
	free_ht_item(del->item);
	return (item);
}

/*
	Free the list
*/
void	ft_free_list(t_linkdlst *head)
{
	t_linkdlst	*current;
	t_linkdlst	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_ht_item(current->item);
		free (current);
		current = next;
	}
}
