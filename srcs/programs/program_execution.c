/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 10:10:54 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/21 10:10:55 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_dir_or_file(t_my_env **my_env, char **params, int *status);
static int	other_exec(t_my_env **my_env, char **params);
static int	choose_program(t_my_env **my_env, char **params, int *is_exit,
				char *program_path);
static void	proc_is_dir(t_my_env **my_env, char **params, int *status,
				struct stat file_stat);

int	program_execution(t_my_env **my_env, char **params, int *is_exit)
{
	int		status;
	char	*program_path;

	if (params == NULL)
		return (0);
	program_path = find_builtin_program(*my_env, params[0]);
	status = choose_program(my_env, params, is_exit, program_path);
	free(program_path);
	return (status);
}

static int	other_exec(t_my_env **my_env, char **params)
{
	int	status;

	if (is_dir_or_file(my_env, params, &status) == 0)
	{
		ft_putstr_fd("command not found: ", 2);
		ft_putstr_fd(params[0], 2);
		ft_putstr_fd("\n", 2);
		status = 127;
	}
	return (status);
}

static int	is_dir_or_file(t_my_env **my_env, char **params, int *status)
{
	char		*absolute_path;
	char		*slash_ptr;
	struct stat	file_stat;

	slash_ptr = ft_strchr(params[0], '/');
	if (slash_ptr == NULL && qnty_str(params) > 1)
		return (0);
	absolute_path = get_absolute_path(params[0]);
	if (stat(absolute_path, &file_stat) == -1)
	{
		free(absolute_path);
		return (0);
	}
	if (S_ISDIR(file_stat.st_mode) || S_ISREG(file_stat.st_mode))
	{
		proc_is_dir(my_env, params, status, file_stat);
		free(absolute_path);
		return (1);
	}
	if (slash_ptr != NULL)
	{
		ft_putstr_fd("no such file or directory: ", 2);
		ft_putstr_fd(params[0], 2);
		ft_putstr_fd("\n", 2);
		*status = 1;
		free(absolute_path);
		return (1);
	}
	free(absolute_path);
	return (0);
}

static int	choose_program(t_my_env **my_env, char **params, int *is_exit,
				char *program_path)
{
	static int	status;

	if (ft_strncmp(params[0], "echo", 5) == 0)
		status = my_echo(params);
	else if (ft_strncmp(params[0], "cd", 3) == 0)
		status = my_cd(my_env, params);
	else if (ft_strncmp(params[0], "pwd", 4) == 0)
		status = my_pwd(params);
	else if (ft_strncmp(params[0], "export", 7) == 0)
		status = my_export(my_env, params);
	else if (ft_strncmp(params[0], "unset", 6) == 0)
		status = my_unset(my_env, params);
	else if (ft_strncmp(params[0], "env", 4) == 0)
		status = my_environment(*my_env, params);
	else if (ft_strncmp(params[0], "exit", 5) == 0)
		status = my_exit(status, params, is_exit);
	else if (params[0][0] == '.' && params[0][1] == '/')
		status = bin_exec(my_env, params);
	else if (program_path != NULL)
		status = builtin_program_exec(*my_env, params, program_path);
	else
		status = other_exec(my_env, params);
	return (status);
}

static void	proc_is_dir(t_my_env **my_env, char **params, int *status,
				struct stat file_stat)
{
	char	**cd_param;

	if (qnty_str(params) > 1 || S_ISREG(file_stat.st_mode))
	{
		ft_putstr_fd("permission denied: ", 2);
		ft_putstr_fd(params[0], 2);
		ft_putstr_fd("\n", 2);
		*status = 1;
	}
	else
	{
		cd_param = malloc(sizeof(char *) * 3);
		if (*cd_param == NULL)
			error_message();
		cd_param[0] = ft_strdup("cd");
		cd_param[1] = ft_strdup(params[0]);
		cd_param[2] = NULL;
		*status = my_cd(my_env, cd_param);
		free_arr_of_str(&cd_param);
	}
}
