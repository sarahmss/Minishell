/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:13:05 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/20 20:37:51 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

void	push_process(t_process **lst, t_process *new_p)
{
	t_process	*last;

	if (*lst == NULL)
		*lst = new_p;
	else
	{
		last = *lst;
		while (last->next != NULL)
			last = last->next;
		last->next = new_p;
		new_p->prev = last;
	}
}

void	parse_words(t_process *p, t_token *tokens, int i[])
{
	char	*word;

	word = ft_strdup(tokens->value);
	if (p->command == NULL && tokens->type == T_BUILTIN)
		p->command = word;
	else
	{
		if (i[I_ARGV] == 0 && p->command == NULL)
			p->command = ft_strdup(word);
		p->argv[i[I_ARGV]] = word;
		i[I_ARGV]++;
	}
}

int	parse_iredirect(t_process *p, t_token **tk, int i[])
{
	t_token			*token;
	t_file			*input;

	*tk = (*tk)->next;
	token = *tk;
	if (token->type != T_WORD)
		return (EPARSE);
	input = malloc(sizeof(t_file));
	if (!input)
		return (ERRSYS);
	input->path = ft_strdup(token->value);
	input->flags = 2;
	p->input_file[i[I_IRED]] = input;
	i[I_IRED]++;
	return (0);
}

int	parse_oredirect(t_process *p, t_token **tk, t_bool append, int i[])
{
	t_token	*token;
	t_file	*outfile;

	*tk = (*tk)->next;
	token = *tk;
	if (token->type != T_WORD)
		return (EPARSE);
	outfile = malloc(sizeof(t_file));
	if (!outfile)
		return (ERRSYS);
	outfile->path = ft_strdup(token->value);
	if (append == true)
		outfile->flags = 1;
	if (append == false)
		outfile->flags = 0;
	p->output_file[i[I_ORED]] = outfile;
	i[I_ORED]++;
	return (0);
}

t_process	*parse_command(t_token **tokens)
{
	t_process	*process;
	int			*i;
	t_token		*temp;

	process = ft_calloc(1, sizeof(t_process));
	i = ft_calloc(4, sizeof(int));
	if (!process)
		return (NULL);
	temp = *tokens;
	while (temp != NULL)
	{
		if (temp->type == T_WORD || temp->type == T_BUILTIN)
			parse_words(process, temp, i);
		else if (temp->type == T_IREDIRECT)
			parse_iredirect(process, &temp, i);
		else if (temp->type == T_OREDIRECT)
			parse_oredirect(process, &temp, false, i);
		else if (temp->type == T_OAPPEND)
			parse_oredirect(process, &temp, true, i);
		temp = temp->next;
	}
	free (i);
	return (process);
}
