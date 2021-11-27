/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seulogin <seue-mail@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:29 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/26 14:19:00 by seulogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*aux_strtok(char *input)
{
	char	*result;

	if (input == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(input) + 1));
	if (!result)
		return (NULL);
	return (result);
}

/*
	tokenizing a string based on a delimiter
*/
char	*ft_strtok(char *str, char delimiter)
{
	static char	*input;
	char		*result;
	int			i;

	i = 0;
	input = NULL;
	if (str != NULL)
		input = str;
	result = aux_strtok(input);
	while (input[i] != "\0")
	{
		if (input[i] != delimiter)
			result[i] = input[i];
		else
		{
			result[i] = '\0';
			input = input + i + 1;
			return (result);
		}
		i++;
	}
	result[i] = '\0';
	input = NULL;
	return (result);
}
