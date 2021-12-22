/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:18:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 21:23:29 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	tk_builtin(char *value)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("echo", value) || ft_strcmp("unset", value))
		ret = 1;
	if (ft_strcmp("exit", value) || ft_strcmp("export", value))
		ret = 1;
	if (ft_strcmp("cd", value) || ft_strcmp("env", value))
		ret = 1;
	if (ft_strcmp("pwd", value))
		ret = 1;
	return (ret);
}

void	tk_define_types(t_token *head)
{
	t_token	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (tk_builtin(temp->value))
			temp->type = T_BUILTIN;
		else if (ft_strcmp(">", temp->value))
			temp->type = T_OREDIRECT;
		else if (ft_strcmp(">>", temp->value))
			temp->type = T_OAPPEND;
		else if (ft_strcmp("<", temp->value))
			temp->type = T_IREDIRECT;
		else if (ft_strcmp("<<", temp->value))
			temp->type = T_IREADNOHISTORY;
		else
			temp->type = T_WORD;
		temp = temp->next;
	}
}
