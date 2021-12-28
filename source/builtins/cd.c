/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smodesto <smodesto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:04:04 by smodesto          #+#    #+#             */
/*   Updated: 2021/12/27 22:00:25 by smodesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Minishell.h"

static	char	*get_wd(void)
{
	char	*cwd;

	cwd = NULL;
	cwd = getcwd(NULL, 0);
	return (cwd);
}

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

static	t_bool	update_cwd(t_ht_tab *env, char *old_pwd)
{
	char	*cwd;

	cwd = get_wd();
	if (cwd == NULL)
		return (false);
	update_var(env, "OLDPWD", old_pwd);
	update_var(env, "PWD", cwd);
	return (true);
}

t_bool	ft_cd(t_process *p, t_ht_tab *env)
{
	t_ht_item	*temp;
	t_ht_item	*var;
	char		*old_pwd;

	var = ht_search(env, "PWD");
	old_pwd = var->value;
	if (!p->argv[1])
	{
		temp = ht_search(env, "HOME");
		chdir(temp->value);
	}
	else if (p->argv[2] == NULL)
	{
		if (chdir(p->argv[1]) == -1)
		{
			ft_check_error(ECOMMAND, "cd: Dir not exists", NULL);
			return (false);
		}
	}
	return (update_cwd(env, old_pwd));
}
