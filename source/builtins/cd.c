/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:04:04 by smodesto          #+#    #+#             */
/*   Updated: 2022/03/01 20:24:23 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static void	update_var(t_ht_tab *env, char *key, char *pwd)
{
	t_ht_item	*v;
	char		*cwd;

	v = ht_search(env, key);
	if (v)
	{
		free(v->value);
		v->value = pwd;
	}
	else
	{
		if (!pwd)
			cwd = ft_strdup(key);
		else
			cwd = ft_join_var(3, key, "=", pwd);
		set_value(env, cwd, 0);
		free(cwd);
		free(pwd);
	}
}

static	int	update_cwd(t_ht_tab *env, char *old_pwd, char *dir)
{
	char	*cwd;

	if (dir)
		free (dir);
	cwd = working_directory(0);
	if (cwd == NULL)
		return (false);
	update_var(env, "OLDPWD", old_pwd);
	update_var(env, "PWD", cwd);
	return (0);
}

static int	leave(char *s1, char *s2, int mood)
{
	if (s1 != NULL)
		free (s1);
	if (s2 != NULL)
		free (s2);
	if (mood == 1)
		return (ft_check_error(ECOMMAND, "cd: invalid arguments", NULL));
	if (mood == 2)
		ft_check_error(ECOMMAND, "cd: Dir not exists", NULL);
	else if (mood == 3)
		ft_check_error(ECOMMAND, "cd: HOME not set", NULL);
	return (1);
}

static int	cd_minus(t_ht_item *old_pwd, t_ht_tab *env)
{
	if (old_pwd == NULL)
		return (ft_check_error(ECOMMAND, "cd: OLDPWD not set", NULL));
	chdir(old_pwd->value);
	printf("%s\n", old_pwd->value);
	update_var(env, "PWD", ft_strdup(old_pwd->value));
	return (0);
}

int	ft_cd(t_ht_tab *env, char **argv)
{
	t_ht_item	*temp;
	char		*old_pwd;
	char		*dir;

	dir = NULL;
	if (ft_strcmp(argv[1], "-"))
		return (cd_minus(ht_search(env, "OLDPWD"), env));
	temp = ht_search(env, "PWD");
	old_pwd = ft_strdup(temp->value);
	if (!argv[1] || ft_strcmp(argv[1], "~") || ft_strcmp(argv[1], "~/"))
	{
		temp = ht_search(env, "HOME");
		if (temp == NULL)
			return (leave(NULL, old_pwd, 3));
		chdir(temp->value);
	}
	else if (argv[2] != NULL)
		return (leave(old_pwd, NULL, 1));
	else
	{
		dir = ft_strtrim(argv[1], "\'\"");
		if (chdir(dir) == -1)
			return (leave(dir, old_pwd, 2));
	}
	return (update_cwd(env, old_pwd, dir));
}
