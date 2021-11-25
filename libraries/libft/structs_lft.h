/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_lft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:11:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/24 11:39:06 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_LFT_H
# define STRUCTS_LFT_H

#include "libft.h"

typedef struct s_format
{
	va_list	args;
	char	*temp;
	int		printed;
}			t_format;

typedef struct s_positions
{
	size_t	i;
	size_t	j;
	size_t	k;
	int		sign;
	char	*stemp;
}	t_positions;

typedef struct s_conversion
{
	int						i;
	long int				numb;
	char					*hex;
	char					*str;
}	t_conversion;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif