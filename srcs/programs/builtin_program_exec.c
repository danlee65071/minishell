/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_program_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:23:56 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 12:23:57 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	builtin_program_exec(t_my_env *my_env, char **params,
							 char *program_path)
{
	char	**str_env;
	pid_t	program_pid;
	int		status;

	program_pid = fork();
	if (program_pid == 0)
	{
		str_env = my_env_to_str(my_env);
		execve(program_path, params, str_env);
	}
	waitpid(program_pid, &status, 0);
	return (status);
}
