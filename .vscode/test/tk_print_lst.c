/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:06:22 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/11 10:06:23 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	tk_print_lst(t_token *lst)
{
	t_token	*temp;

	temp = lst;
	while (temp != NULL)
	{
		printf("%s\n", temp->value);
		temp = temp->next;
	}
}
