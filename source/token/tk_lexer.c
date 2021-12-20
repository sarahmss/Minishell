/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tk_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:18:46 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 12:55:42 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

int	tk_builtin(t_token	*tk)
{
	int	ret;

	ret = 0;
	if (ft_strcmp("echo", tk->value) || ft_strcmp("unset", tk->value))
		ret = 1;
	if (ft_strcmp("exit", tk->value) || ft_strcmp("export", tk->value))
		ret = 1;
	if (ft_strcmp("cd", tk->value) || ft_strcmp("env", tk->value))
		ret = 1;
	if (ft_strcmp("pwd", tk->value))
		ret = 1;
	return (ret);
}

void	tk_define_types(t_token *head)
{
	t_token	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (tk_builtin(temp))
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
