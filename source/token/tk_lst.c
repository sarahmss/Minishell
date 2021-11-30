/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 09:58:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/30 17:42:00 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
Creates a new element at a doubly linked list and storage value in it
*/
t_token	*tk_get_new_tok(char *value, t_cmd_tab *tab)
{
	t_token	*new_tok;

	new_tok = (t_token *)malloc(sizeof(t_token));
	if (!new_tok)
		ft_check_error(-2, "CREATING TOKEN", tab);
	new_tok->value = ft_strdup(value);
	new_tok->prev = NULL;
	new_tok->next = NULL;
	return (new_tok);
}

/*
Insert a new element at the top of a doubly linked list
*/
t_token	*tk_insert_at_head(char *value, t_token *head, t_cmd_tab *tab)
{
	t_token	*new_tok;

	new_tok = tk_get_new_tok(value, tab);
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
Insert a new element at the bottom of a doubly linked list
*/
void	tk_insert_at_foot(char *value, t_token *head, t_cmd_tab *tab)
{
	t_token	*new_node;
	t_token	*temp;

	new_node = tk_get_new_tok(value, tab);
	temp = head;
	if (temp->next == NULL)
	{
		head->next = new_node;
		new_node->prev = head;
	}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
	}
}

/*
	Delete a tok del in the list
*/
void	tk_del(t_token **head, t_token *del)
{
	if (*head == NULL || del == NULL)
		return ;
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
