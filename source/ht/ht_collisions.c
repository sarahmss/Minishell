/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht_collisions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:25:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 17:52:50 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	ht_collision(t_ht_tab *ht, unsigned long int in, t_ht_item *it)
{
	t_linkdlst	*head;

	head = ht->overflow_buckets[in];
	if (head == NULL)
	{
		head = ft_insert_at_head(it, NULL);
		ht->overflow_buckets[in] = head;
	}
	else
		ht->overflow_buckets[in] = ft_insert_at_head(it, head);
}

t_linkdlst	**create_overflow_buckets(t_ht_tab *ht_tab)
{
	int			i;
	t_linkdlst	**buckets;

	buckets = (t_linkdlst **)calloc(ht_tab->size, sizeof(t_linkdlst *));
	if (!buckets)
		ft_check_error(EALLOC, "CREATING BUCKETS", NULL);
	i = 0;
	while (i < ht_tab->size)
	{
		buckets[i] = NULL;
		i++;
	}
	return (buckets);
}

void	free_overflow_buckets(t_ht_tab *ht_tab)
{
	int			i;
	t_linkdlst	**buckets;

	buckets = ht_tab->overflow_buckets;
	i = 0;
	while (i < ht_tab->size)
	{
		ft_free_list(buckets[i]);
		i++;
	}
	free(buckets);
}
