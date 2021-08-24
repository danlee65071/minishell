/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:47:15 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/21 10:47:16 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	process_qnty_params(int qnty_params, char **params);
static void	error_message_cd(char *path, char **old_pwd);
static int	cd_exec(t_my_env **my_env, char **params, t_cd *cd);

int	my_cd(t_my_env **my_env, char **params)
{
	t_cd	cd;

	cd.qnty_params = qnty_str(params);
	update_old_pwd(my_env, &cd.old_pwd);
	if (process_qnty_params(cd.qnty_params, params) == 0)
		return (1);
	if (cd_exec(my_env, params, &cd) == 1)
		return (1);
	free(cd.old_pwd);
	free(cd.pwd);
	return (0);
}

static int	process_qnty_params(int qnty_params, char **params)
{
	if (qnty_params == 3)
	{
		ft_putstr_fd("cd: string not in cd.pwd: ", 2);
		ft_putstr_fd(params[1], 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	else if (qnty_params > 3)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (0);
	}
	return (1);
}

char	*get_absolute_path(char *path)
{
	char	*absolute_path;
	char	*current_path;
	char	*tmp_str;

	if (path[0] == '/')
		absolute_path = ft_strdup(path);
	else
	{
		current_path = getcwd(NULL, BUF_SIZE);
		absolute_path = ft_strjoin(current_path, "/");
		tmp_str = absolute_path;
		absolute_path = ft_strjoin(absolute_path, path);
		free(tmp_str);
		free(current_path);
	}
	return (absolute_path);
}

static void	error_message_cd(char *path, char **old_pwd)
{
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd("\n", 2);
	free(*old_pwd);
}

static int	cd_exec(t_my_env **my_env, char **params, t_cd *cd)
{
	if (cd->qnty_params == 1)
	{
		if (chdir(get_var_value_from_env(*my_env, "HOME")) == -1)
		{
			error_message_cd("", &(cd->old_pwd));
			return (1);
		}
		update_pwd(my_env, &(cd->pwd));
	}
	else
	{
		cd->absolute_path = get_absolute_path(params[1]);
		if (chdir(cd->absolute_path) == -1)
		{
			error_message_cd(params[1], &(cd->old_pwd));
			return (1);
		}
		update_pwd(my_env, &(cd->pwd));
		free(cd->absolute_path);
	}
	return (0);
}
