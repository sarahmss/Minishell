/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 08:31:18 by smodesto          #+#    #+#             */
/*   Updated: 2021/05/28 12:37:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		nodes;

	nodes = 1;
	current = lst;
	if (current == NULL)
		return (0);
	while (current->next != NULL)
	{
		nodes++;
		current = current->next;
	}
	return (nodes);
}
