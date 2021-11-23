
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 08:51:24 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/23 11:54:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

#include "./Minishell.h"

#define CAPACITY 50000

typedef struct s_ht_item
{
    char    *key;
    char    *value;
}   t_ht_item;

typedef struct s_ht_table
{
    t_ht_item   **items;
    t_node      **overflow_buckets;
    int         size;
    int         count;    
}   t_ht_table;



unsigned long   hash_function(char *str);
void            free__ht_table(t_ht_table *ht_table);
void             free_ht_item(t_ht_item *ht_item);
t_ht_table      *create_table(int size, t_command_table *table);
t_ht_item       *create_item(char *key, char *value, t_command_table *table);
void            ht_insert(t_ht_table *ht_table, char *key, char *value, t_command_table *table);

#endif

