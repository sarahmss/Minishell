/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:08:45 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 19:23:53 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

unsigned long hash_function(char *str)
{
    unsigned long hash;
    int           j;
    
    hash = 0;
    j = 0;
    while (str[j])
    {
        hash += str[j];
        j++;
    }
    return (hash % CAPACITY);
}

t_ht_item   *create_item(char *key, char *value, t_command_table *table)
{
    t_ht_item   *item;

    item = (t_ht_item *)malloc(sizeof(t_ht_item));
    if (!item)
        ft_check_error(1, "CREATING ITEM", table);    
    item->key = ft_strdup(key);
    value = ft_strdup(value);
    return (item);
}

t_ht_table  *create_table(int size, t_command_table *table)
{
    t_ht_table   *ht_table;
    int i;

    i = 0;
    ht_table = (t_ht_table *)malloc(sizeof(t_ht_table));
    if (!ht_table)
        ft_check_error(1, "CREATING TABLE", table); 
    ht_table->size = size;
    ht_table->count = 0;   
    ht_table->items = (t_ht_item **)ft_calloc(size, (sizeof(t_ht_item)));   
    while (i < size)
    {
        ht_table->items[i] = NULL;
        i++;
    }
    ht_table->overflow_buckets = create_overflow_buckets();
}

void    free_ht_item(t_ht_item *ht_item)
{
    free(ht_item->key);
    free(ht_item->value);
    free(ht_item);    
}

void    free__ht_table(t_ht_table *ht_table)
{
    int         i;
    t_ht_item   *item;

    i = 0;
    while (i < ht_table->size)
    {
        item = ht_table->items[i];
        if (item != NULL)
            free_ht_item(item);
        i++;
    }
    
}