/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 21:45:41 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/02 19:12:33 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	echo [-neE] [arg ...]
	Display the ARGs, separated by a single space character and followed by a
	newline, on the standard output.
	-n	do not append a newline
*/

#include "../includes/Minishell.h"

int	ft_echo(char **argv)
{
	t_bool	flag_n;
	int		i;
	char	*temp;

	i = 1;
	flag_n = false;
	if (argv[1] != NULL && ft_strcmp(argv[1], "-n"))
	{
		while (ft_strcmp(argv[i], "-n"))
			i++;
		flag_n = true;
	}
	while (argv[i] != NULL)
	{
		temp = ft_strtrim(argv[i], "\"\' ");
		if (argv[i + 1] != NULL)
			printf("%s ", temp);
		else
			printf("%s", temp);
		i++;
		free (temp);
	}
	if (flag_n == false)
		printf("\n");
	return (0);
}
