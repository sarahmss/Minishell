/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:54 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/01 12:13:16 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H

# define C_SQUOTE	'\''
# define C_DQUOTE	'"'
# define C_ESCAPE	'\\'
# define C_PIPE		'|'
# define C_LESS		'<'
# define C_GREATER	'>'
# define C_SMCOLON	';'
# define C_SPACE	' '
# define C_NULL		'\0'
# define C_GENERAL	-1

typedef enum e_type
{
	T_UNDEFINED,
	T_WORD,
	T_SEPARATOR,
	T_PIPE,
	T_END_OF_LINE,
	T_IREDIRECT,
	T_OREDIRECT,
	T_OAPPEND
}					t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

// split cmd
char			*ft_strtok(char *str, char delimiter);
t_token			*tk_split_cmd(char *line, char delimiter, t_cmd_tab *tab);
void			dq_cmd_tab(t_cmd_tab *tab, char **old, char c);
int				dq(char	*line, char c);
char			*insert_spaces(char *line, t_cmd_tab *tab);

// Tk lst
t_token			*tk_get_new_tok(char *value, t_cmd_tab *tab);
void			tk_insert_at_foot(char *value, t_token *head, t_cmd_tab *tab);
t_token			*tk_insert_at_head(char *value, t_token *head, t_cmd_tab *tab);
void			tk_del(t_token **head, t_token *del);
void			tk_free_lst(t_token *head);

//
t_token			*tk_create_tokens(t_cmd_tab *tab, char **cmd_splitted);
void			tokenizer(t_cmd_tab *tab);
t_token			**pipe_cmd_line(t_cmd_tab *tab);
#endif
