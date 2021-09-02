/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 13:07:49 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/31 13:07:51 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*get_program_path(char **params);
static void	directory_error_message(char **params);

int	bin_exec(t_my_env **my_env, char **params)
{
	t_bin	bin;

	bin.program_pid = fork();
	if (bin.program_pid == 0)
	{
		bin.str_env = my_env_to_str(*my_env);
		bin.program_path = get_program_path(params);
		if (stat(bin.program_path, &bin.file_stat) == -1
			|| S_ISDIR(bin.file_stat.st_mode))
		{
			if (S_ISDIR(bin.file_stat.st_mode))
			{
				directory_error_message(params);
				exit (126);
			}
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(params[0], 2);
			ft_putstr_fd("\n", 2);
			exit (1);
		}
		execve(bin.program_path, params, bin.str_env);
	}
	waitpid(bin.program_pid, &bin.status, 0);
	return (bin.status % 255);
}

static char	*get_program_path(char **params)
{
	char	*program_path;

	program_path = getcwd(NULL, BUF_SIZE);
	program_path = ft_strjoin(program_path, "/");
	program_path = ft_strjoin(program_path, params[0] + 2);
	return (program_path);
}

static void	directory_error_message(char **params)
{
	ft_putstr_fd("is a directory: ", 2);
	ft_putstr_fd(params[0], 2);
	ft_putstr_fd("\n", 2);
}
