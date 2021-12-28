/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errcode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:32:49 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 20:23:27 by smodesto         ###   ########.fr       */
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
	ECMDNF,
	ECOMMAND,
	ENUMARG,
	EALLOC,
	__ERRMAX
}					t_errcode;

#endif
