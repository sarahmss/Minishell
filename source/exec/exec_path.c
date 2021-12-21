/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:28:09 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/21 17:51:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

/*
	stat function check status of file such as permissions and type
	S_IXUSR = check if it is executable
*/
static t_bool	is_executable(char *path_cmd)
{
	struct stat	buffer;

	if (stat(path_cmd, &buffer) != 0)
		return (false);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
		return (false);
	if ((buffer.st_mode & S_IXUSR))
		return (true);
	return (false);
}

char	*find_full_path(t_ht_tab *env, char *command)
{
	t_ht_item	*path;
	char		**path_split;
	int			i;
	char		*final_path;

	i = 0;
	path = ht_search(env, "PATH");
	path_split = ft_split(path->value, ':');
	while (path_split[i] != NULL)
	{
		final_path = ft_strjoin_variadic(3, path_split[i], "/", command);
		if (is_executable(final_path) == true)
		{
			free_matrix(path_split);
			return (final_path);
		}
		free(final_path);
		i++;
	}
	free_matrix(path_split);
	return (NULL);
}
