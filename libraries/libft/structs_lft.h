/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_lft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulogin <seue-mail@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:11:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/27 09:52:22 by seulogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_LFT_H
# define STRUCTS_LFT_H

# include "libft.h"

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
