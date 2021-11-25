/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_collisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:25:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/25 18:16:42 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void    handle_collision(t_ht_tab *ht_tab, unsigned long int index , t_ht_item *item)
{
    t_linkdlst  *head;

    head = ht_tab->overflow_buckets[index];
    if (head == NULL)
    {
        head = ft_insert_at_head(item, NULL);
        ht_tab->overflow_buckets[index] = head;
    }
    else
        ht_tab->overflow_buckets[index] = ft_insert_at_head(item, head);
}

t_linkdlst  **create_overflow_buckets(t_ht_tab *ht_tab, t_cmd_tab *table)
{
    int         i;
    t_linkdlst  **buckets;
    
    buckets = (t_linkdlst  **)calloc(ht_tab->size, sizeof(t_linkdlst *));
    if (!buckets)
        ft_check_error(1, "CREATING BUCKETS", table);
    i = 0;
    while (i < ht_tab->size)
    {
        buckets[i] = NULL;
        i++;
    }
    return (buckets);   
}

void        free_overflow_buckets(t_ht_tab *ht_tab)
{
    int     i;
    t_linkdlst  **buckets;
    
    buckets = ht_tab->overflow_buckets;
    i = 0;
    while (i < ht_tab->size)
    {
        ft_free_list(buckets[i]);
        i++;
    }
    free(buckets);   
}