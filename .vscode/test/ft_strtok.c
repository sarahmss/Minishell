/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 13:21:29 by smodesto          #+#    #+#             */
/*   Updated: 2021/11/29 10:30:57 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static char	*double_quotes(char *input, t_tok *tok)
{
	char	*result;
	char	*new_input;

	if (tok->double_quotes)
	{
		tok->double_quotes = 0;
		result = ft_strchr(input, '"');
		result++;
		new_input = ft_strchr(result, '"');
		new_input++;
		result = ft_strcdup(result, '"');
		if (*new_input == '\0')
			tok->input = NULL;
		else
			tok->input = input + ft_strlen(result) + 3;
		if (tok->input[1])
	}
	return (result);
}

static void	find_dq(char *input, int i, t_tok *tok)
{
	if (input[i + 1] == '"')
		tok->double_quotes = 1;
}

static char	*aloc_result(char *str, t_tok *tok)
{
	char	*result;

	if (str != NULL)
		tok->input = str;
	if (tok->input == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(tok->input) + 1));
	if (!result)
		return (NULL);
	return (result);
}

/*
	tokenizing a string based on a delimiter
*/
char	*ft_strtok(char *str, char delimiter, t_cmd_tab *tab, t_tok *tok)
{
	char		*result;
	int			i;

	i = 0;
	if (tok->double_quotes == 1)
		return (double_quotes(tok->input, tok));
	result = aloc_result(str, tok);
	if (result == NULL)
		return (NULL);
	while (tok->input[i] != '\0')
	{
		if (tok->input[i] != delimiter)
			result[i] = tok->input[i];
		else
		{
			find_dq(tok->input, i, tab->tok);
			result[i] = '\0';
			tok->input = tok->input + i + 1;
			return (result);
		}
		i++;
	}
	result[i] = '\0';
	tok->input = NULL;

	return (result);
}
