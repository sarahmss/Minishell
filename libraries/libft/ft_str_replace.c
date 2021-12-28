/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_race.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:38:37 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/13 14:55:06 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	times(char *ins, char *rep, char *tmp, int l_rep)
{
	int		count;

	count = -1;
	tmp = ft_strnstr(ins, rep, ft_strlen(ins));
	while (tmp)
	{
		tmp = ft_strnstr(ins, rep, ft_strlen(ins));
		ins = tmp + l_rep;
		count++;
	}
	return (count);
}

static int	imod(int a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

char	*str_replace(char *orig, char *rep, char *with)
{
	t_replace	r;

	r.tmp = NULL;
	if (!orig || !rep || !with)
		return (NULL);
	r.l_rep = ft_strlen(rep);
	r.l_with = ft_strlen(with);
	r.ins = orig;
	r.count = times(r.ins, rep, r.tmp, r.l_rep);
	r.ins = r.tmp + r.l_rep;
	r.result = malloc(ft_strlen(orig) + imod(r.l_with - r.l_rep) * r.count + 1);
	r.tmp = r.result;
	if (!r.result)
		return (NULL);
	while (r.count--)
	{
		r.ins = ft_strnstr(orig, rep, ft_strlen(orig));
		r.l_front = r.ins - orig;
		r.tmp = ft_strncpy(r.tmp, orig, r.l_front) + r.l_front;
		r.tmp = ft_strcpy(r.tmp, with) + r.l_with;
		orig += r.l_front + r.l_rep;
	}
	ft_strcpy(r.tmp, orig);
	return (r.result);
}
