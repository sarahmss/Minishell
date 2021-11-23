/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_collisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:25:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 19:38:40 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void    handle_collision(t_ht_table *ht_table, int item)
{
 
}

void create_overflow_buckets(t_ht_table *ht_table, t_command_table *table)
{
    int     i;
    t_node  **buckets;
    
    buckets = (t_node  **) calloc (ht_table->size, sizeof(t_node *));
    i = 0;
    while (i < ht_table->size)
    {
         buckets[i] = NULL;
        i++;
    }
    return (buckets);   
}

void free_overflow_buckets(t_ht_table *ht_table, t_command_table *table)
{
    int     i;
    t_node  **buckets;
    
    buckets = (t_node  **) calloc (ht_table->size, sizeof(t_node *));
    i = 0;
    while (i < ht_table->size)
    {
        stack_del(buckets[i]);
        i++;
    }
    return (buckets);   
}