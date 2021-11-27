/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 09:59:13 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 10:04:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H
# include "./Minishell.h"
# define CAPACITY 50000

//	Hash table item
typedef struct s_ht_item
{
	char	*key;
	char	*value;
}	t_ht_item;

//  Double linked list
typedef struct s_linkdlst
{
	t_ht_item			*item;
	struct s_linkdlst	*next;
	struct s_linkdlst	*prev;
}	t_linkdlst;

//  Hash table
typedef struct s_ht_tab
{
	t_ht_item	**items;
	t_linkdlst	**overflow_buckets;
	int			size;
	int			count;
}	t_ht_tab;

// hash_table
unsigned long	hash_function(char *str);
void			free_ht_tab(t_ht_tab *ht_tab);
void			free_ht_item(t_ht_item *ht_item);
t_ht_tab		*create_table(int size, t_cmd_tab *table);
t_ht_item		*create_item(char *key, char *value, t_cmd_tab *table);

// ht utils
void			ht_insert(t_ht_tab *ht_tab, char *key, char *value, t_cmd_tab *table);
char			*ht_search(t_ht_tab *ht_tab, char *key);
void			ht_delete(t_ht_tab *ht_tab, char *key, t_cmd_tab *tab);

// colisions
void			free_overflow_buckets(t_ht_tab *ht_tab);
t_linkdlst		**create_overflow_buckets(t_ht_tab *ht_tab, t_cmd_tab *table);
void			ht_collision(t_ht_tab *ht_tab, unsigned long int index, t_ht_item *item);

// lstdoubly
t_linkdlst		*ft_insert_at_head(t_ht_item *item, t_linkdlst *head);
void			ft_free_list(t_linkdlst *head);
t_ht_item		*node_del(t_linkdlst **head, t_linkdlst *del);
#endif
