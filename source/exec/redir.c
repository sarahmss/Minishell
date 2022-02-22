/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:11:28 by smodesto          #+#    #+#             */
/*   Updated: 2022/02/22 15:26:35 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static int	create_heredoc(char *path)
{
	int		fd;

	fd = open(path, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < -1)
	{
		perror("error");
		return (0);
	}
	return (fd);
}

static void	here_doc_sig(void)
{
	signal(SIGINT, sig_doc);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}

void	read_write_heredoc(char *delimiter, int fd, char *path, int *new_fd)
{
	char	*line;
	int		tmp_fd[2];

	here_doc_sig();
	handle_fd(new_fd, tmp_fd);
	while (1)
	{
		line = readline(">");
		if (line == NULL)
		{
			if (path)
				free(path);
			ft_check_error(-1, "here-doc delimited by EOF\n", NULL);
		}
		if (ft_strcmp(line, delimiter))
		{
			free(line);
			break ;
		}
		else
			ft_putendl_fd(line, fd);
		free(line);
	}
	handle_fd(new_fd, tmp_fd);
	exit(0);
}

static char	**def_arg(char *argv[], char *file_name)
{
	argv[0] = ft_strdup("rm");
	argv[1] = ft_strdup("-rf");
	argv[2] = ft_strdup(file_name);
	argv[3] = NULL;
	return (argv);
}

int	redir(char *delimiter, t_session *s)
{
	int		fd;
	int		pid;
	char	*path;
	char	*argv[4];

	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	path = ft_join_var(2, "/tmp/", delimiter);
	remove_temp_fd(def_arg(argv, path), s);
	fd = create_heredoc(path);
	if (fd < 0)
	{
		free(path);
		return (0);
	}
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		read_write_heredoc(delimiter, fd, path, s->std_fd);
	else
		waitpid(pid, &s->stat, 0);
	if (path)
		free(path);
	return (fd);
}
