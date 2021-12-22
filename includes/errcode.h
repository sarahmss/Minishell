/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:32:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/22 13:05:38 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRCODE_H
# define ERRCODE_H

# include "./Minishell.h"
# include <errno.h>

typedef enum e_errcode
{
	ERRSYS = 0,
	SIGEXIT,
	EUSAGE,
	ENOFDI,
	EPARSE,
	EUNFQT,
	ENOTVI,
	ECMDNF,
	ECOMMAND,
	ESYNTAX,
	ENUMARG,
	EALLOC,
	__ERRMAX
}					t_errcode;

#endif
