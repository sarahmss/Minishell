/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 09:10:58 by smodesto          #+#    #+#             */
/*   Updated: 2021/09/10 19:40:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	if (matrix)
		free (matrix);
	matrix = NULL;
}

static void	ft_strsep(char *dest, char *src, char c)
{
	while (*src && *src != c)
		*dest++ = *src++;
}

char	**make_splitted(char **splitted_str, char sep, t_positions pos)
{
	pos.i = 0;
	pos.j = 0;
	while (*pos.stemp)
	{
		if (*pos.stemp != sep)
		{
			while (*pos.stemp != sep && *pos.stemp)
			{
				pos.i++;
				pos.stemp++;
			}
			splitted_str[pos.j] = ft_calloc((pos.i + 1), sizeof(char));
			if (!splitted_str[pos.j])
			{
				free_matrix(splitted_str);
				splitted_str = NULL;
				return (splitted_str);
			}
			ft_strsep(splitted_str[pos.j++], (pos.stemp - pos.i), sep);
			pos.i = 0;
		}
		if (*pos.stemp)
			pos.stemp++;
	}
	return (splitted_str);
}

static char	**ft_alocate(t_positions pos, char sep)
{
	char	**splitted_matrix;

	pos.k = 0;
	while (*pos.stemp)
	{
		if (*pos.stemp != sep)
		{
			while (*pos.stemp != sep && *pos.stemp)
				pos.stemp++;
			pos.k++;
		}
		if (*pos.stemp)
			pos.stemp++;
	}
	splitted_matrix = (char **)ft_calloc((pos.k + 1), sizeof(char *));
	if (!splitted_matrix)
		return (NULL);
	return (splitted_matrix);
}

char	**ft_split(const char *s, char c)
{
	char		**splitted_str;
	t_positions	pos;

	if (s == NULL)
		return (NULL);
	pos.stemp = (char *)s;
	splitted_str = ft_alocate(pos, c);
	if (splitted_str == NULL)
	{
		free(splitted_str);
		return (NULL);
	}
	splitted_str = make_splitted(splitted_str, c, pos);
	if (splitted_str == NULL)
	{
		free(splitted_str);
		return (NULL);
	}
	return (splitted_str);
}
