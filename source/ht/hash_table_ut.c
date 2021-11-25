/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_ut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/25 18:15:14 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
    insert an intem in the hash table
*/ 
void    ht_insert(t_ht_tab *ht_tab, char *key, char *value, t_cmd_tab *table)
{
    t_ht_item *item;
    t_ht_item *current_item;
    int       index;
    
    item = create_item(key, value, table);
    index = hash_function(key);
    current_item = ht_tab->items[index];
    if (current_item == NULL)
    {
        if (ht_tab->count == ht_tab->size)
        {
            ft_check_error(1, "INSERT ERROR: HASH TABLE IS FULL", table);
            free_ht_item(item);
            return ;
        }
        ht_tab->items[index] = item;
        ht_tab->count++;
    }
    else if (ft_strncmp(current_item->key, key, ft_strlen(key)) == 0)
        ht_tab->items[index]->value = ft_strdup(value);
    else
        handle_collision(ht_tab, index, item);
    return ;
}

/*
    search for an intem in the hash table
*/ 
char    *ht_search(t_ht_tab *ht_tab, char *key)
{
    int         index;
    t_ht_item   *item;
    t_linkdlst  *head;
    
    index = hash_function(key);
    item = ht_tab->items[index];
    head = ht_tab->overflow_buckets[index];
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

static void    ht_delete_sup(t_ht_tab *table, t_linkdlst  *head, char *key, int index)
{
    t_linkdlst  *curr;
    t_linkdlst  *prev;

    curr = head;
    prev = NULL;
    while (curr)
    {
        if (ft_strncmp(curr->item->key, key, ft_strlen(key)) == 0)
        {
            if (prev == NULL)
            {
                ft_free_list(head);
                table->overflow_buckets[index] = NULL;
                return;
            }
            else
            {
                prev->next = curr->next;
                curr->next = NULL;
                ft_free_list(curr);
                table->overflow_buckets[index] = head;
                return;
            }
        }
        curr = curr->next;
        prev = curr;
    }
}

/*
    delete an intem in the hash table
*/ 
void    ht_delete(t_ht_tab *ht_tab, char *key, t_cmd_tab *tab)
{
    int         index;
    t_ht_item   *item;
    t_linkdlst  *head;
    t_linkdlst  *node;

    index = hash_function(key);
    item = ht_tab->items[index];
    head = ht_tab->overflow_buckets[index];
    if (item == NULL)
        return ;
    else 
    {
        if (head == NULL && ft_strncmp(item->key, key, ft_strlen(key)) == 0)
        {
            ht_tab->items[index] = NULL;
            free(item);
            ht_tab->count--;
            return ;
        }
        else if (head != NULL)
        {
            if (ft_strncmp(item->key, key, ft_strlen(key)) == 0)
            {
                free_ht_item(item);
                node = head;
                head = head->next;
                node->next = NULL;
                ht_tab->items[index] = create_item(node->item->key, node->item->value, tab);
                ft_free_list(node);
                ht_tab->overflow_buckets[index] = head;
            }
            ht_delete_sup(ht_tab, head, key, index);
        }
    }
}
