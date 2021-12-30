/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:32:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/30 14:03:47 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRCODE_H
# define ERRCODE_H

# include "./Minishell.h"
# include <errno.h>

typedef enum e_errcode
{
	SIGEXIT = 1,
	EUSAGE,
	EPARSE,
	EUNFQT,
	EEMPTYLN,
	ECOMMAND,
	ENUMARG,
	EALLOC,
	ECMDNF = 127,
	SINT = 130,
	SQUIT = 131,
	__ERRMAX
}					t_errcode;

#endif
