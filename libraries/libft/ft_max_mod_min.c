/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_mod_min.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 10:42:51 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/13 10:07:12 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

float	mod(float a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}
