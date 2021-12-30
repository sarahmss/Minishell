/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_lft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:11:44 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/28 16:22:08 by smodesto         ###   ########.fr       */
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
	int		len;
	char	*stemp;
	char	*dq1;
	char	*temp;
}	t_positions;

typedef struct s_conversion
{
	int						i;
	long int				numb;
	char					*hex;
	char					*str;
}	t_conversion;

typedef struct s_replace
{
	char	*result;
	char	*ins;
	char	*tmp;
	int		l_rep;
	int		l_with;
	int		l_front;
	int		count;
}	t_replace;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

#endif
