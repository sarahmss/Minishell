/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:08:36 by smodesto          #+#    #+#             */
/*   Updated: 2021/06/01 11:26:17 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	run_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	char	*str_trim;
	int		i;
	int		start;
	int		end;

	if (str == NULL || set == NULL)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen((char *)str);
	while (str[start] && run_set(str[start], set))
		start++;
	while (end > start && run_set(str[end - 1], set))
		end--;
	str_trim = malloc (sizeof(*str) * (end - start + 1));
	if (str_trim == NULL)
		return (NULL);
	while (start < end)
	{
		str_trim[i] = str[start];
		i++;
		start++;
	}
	str_trim[i] = '\0';
	return (str_trim);
}
