/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:58:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 09:02:48 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
Creates a new element at a doubly linked list and storage value in it
*/
t_token	*ft_get_new_tok(char *value)
{
	t_token	*new_tok;

	new_tok = (t_token *)malloc(sizeof(t_token));
	if (!new_tok)
		return (NULL);
	new_tok->value = value;
	new_tok->prev = NULL;
	new_tok->next = NULL;
	return (new_tok);
}

/*
Insert a new element at the top of a doubly linked list
*/
t_token	*ft_insert_at_head(char *value, t_token *head)
{
	t_token	*new_tok;

	new_tok = ft_get_new_tok(value);
	if (head == NULL)
		head = new_tok;
	else
	{
		head->prev = new_tok;
		new_tok->next = head;
		head = new_tok;
	}
	return (new_tok);
}

/*
	Delete a tok del in the list
*/
void	tok_del(t_token **head, t_token *del)
{

	if (*head == NULL || del == NULL)
		return (NULL);
	if (*head == del)
		*head = del->next;
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del->value);
	free(del);
}

/*
	Free the list
*/
void	tk_free_lst(t_token *head)
{
	t_token	*current;
	t_token	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->value);
		free (current);
		current = next;
	}
}
