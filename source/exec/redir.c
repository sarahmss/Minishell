/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:28 by smodesto          #+#    #+#             */
/*   Updated: 2022/01/25 13:11:54 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	create_heredoc(char *delimiter, char *final_file)
{
	char	*temp;
	int		fd;

	temp = ft_join_var(2, "/tmp/", delimiter);
	fd = open(temp, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	free(temp);
	if (fd == -1)
		return (-1);
	write (fd, final_file, ft_strlen(final_file));
	free(final_file);
	return (fd);
}

int	redir(char *delimiter)
{
	char		*final_file;
	char		*line;
	char		*temp;

	line = readline(">");
	temp = NULL;
	while (!ft_strcmp(line, delimiter))
	{
		if (temp != NULL)
		{
			final_file = ft_join_var(3, temp, "\n", line);
			free (temp);
		}
		else
			final_file = ft_strdup(line);
		free (line);
		line = readline(">");
		temp = final_file;
	}
	free(line);
	return (create_heredoc(delimiter, final_file));
}
