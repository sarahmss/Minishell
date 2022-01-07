/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:42:54 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/06 23:14:55 by smodesto         ###   ########.fr       */
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
# include "./Minishell.h"

// split cmd
char			*ft_strtok(char *str, char delimiter);
t_token			*tk_split_cmd(char *line, char delimiter, t_cmd_tab *tab);
char			*insert_spaces(char *line, t_cmd_tab *tab);

// quotes 1
void			dq_cmd_tab(t_cmd_tab *tab, char **old, char c, char *cmd_line);
int				in_qt(char *str, char c);
char			*substitute_quotes(char *line);
// quotes 2
int				dq(char	*line, char c);
int				check_quotes(char *cmd_line, t_cmd_tab *tab);
int				check_quotes2(char *cmd_line);
char			*remove_qt_inside_qt(char *str, char *c);

// Tk lst
t_token			*tk_get_new_tok(char *value, t_cmd_tab *tab);
void			tk_insert_at_foot(char *value, t_token *head, t_cmd_tab *tab);
t_token			*tk_insert_at_head(char *value, t_token *head, t_cmd_tab *tab);
void			tk_del(t_token **head, t_token *del);
void			tk_free_lst(t_token *head);
void			make_one_source(t_positions *pos, char **old, char **new);

//
t_token			*tk_create_tokens(t_cmd_tab *tab, char **cmd_splitted);
void			tokenizer(t_cmd_tab *tab);
t_token			**pipe_cmd_line(t_cmd_tab *tab);
void			tk_define_types(t_token *head);
int				token_error(t_cmd_tab *tb);
int				tk_builtin(char *value);
#endif
