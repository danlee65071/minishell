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

int	bin_exec(t_my_env **my_env, char **params)
{
	char		**str_env;
	pid_t		program_pid;
	int			status;
	char		*program_path;
	struct stat	file_stat;

	program_pid = fork();
	if (program_pid == 0)
	{
		str_env = my_env_to_str(*my_env);
		program_path = getcwd(NULL, BUF_SIZE);
		program_path = ft_strjoin(program_path, "/");
		program_path = ft_strjoin(program_path, params[0] + 2);
		if (stat(program_path, &file_stat) == -1 || S_ISDIR(file_stat.st_mode))
		{
			if (S_ISDIR(file_stat.st_mode))
			{
				ft_putstr_fd("is a directory: ", 2);
				ft_putstr_fd(params[0], 2);
				ft_putstr_fd( "\n", 2);
				exit (126);
			}
			ft_putstr_fd("no such file or directory: ", 2);
			ft_putstr_fd(params[0], 2);
			ft_putstr_fd( "\n", 2);
			exit (1);
		}
		execve(program_path, params, str_env);
	}
	waitpid(program_pid, &status, 0);
	return (status % 255);
}
