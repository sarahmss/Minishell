/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table_ut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 19:25:24 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void    ht_insert(t_ht_table *ht_table, char *key, char *value, t_command_table *table)
{
    t_ht_item *item;
    t_ht_item *current_item;
    int       index;
    item = create_item(key, value, table);
    index = hash_function(key);
    current_item = ht_table->items[index];
    if (current_item == NULL)
    {
        if (ht_table->count == ht_table->size)
        {
            ft_check_error(1, "INSERT ERROR: HASH TABLE IS FULL", table);
            free_ht_item(item);
            return ;
        }
        ht_table->items[index] = item;
        ht_table->count++;
    }
    else if (ft_strcmp(current_item->key, key) == 0)
        ft_strcpy(ht_table->items[index]->value, value);
    else
        handle_collision(ht_table, item);
    return ;
}

char    *ht_search(t_ht_table *ht_table, char *key, char *value)
{
    int         index;
    t_ht_item   *item;
    
    index = hash_function(key);
    item = ht_table->items[index];
    if (item != NULL) {
        if (ft_strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void    ht_delete(t_ht_table *ht_table, char *key, char *value)
{

}
