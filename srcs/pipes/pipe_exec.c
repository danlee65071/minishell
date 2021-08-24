/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:35:34 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 16:35:35 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	child(t_my_env *my_env, char **params, t_pipe *pipes);
static char	**get_program_params(char **params);
static void	end_pipe_exec(t_my_env *my_env, char **params, t_pipe pipes,
				int *status);
static int	program_exec(t_my_env *my_env, char **params);

int	pipe_exec(t_my_env *my_env, char **params, int *is_exit)
{
	t_pipe	pipes;
	int		status;

	if (ft_strncmp(params[qnty_str(params) - 1], "exit", 5) == 0)
		*is_exit = 1;
	pipes.qnty_pipes = find_pipes(params);
	pipes.pipes_fd = malloc(sizeof(int) * 2 * pipes.qnty_pipes);
	if (pipes.pipes_fd == NULL)
		error_message();
	pipes.i = 0;
	while (pipes.i < pipes.qnty_pipes)
	{
		pipe(pipes.pipes_fd + 2 * pipes.i);
		pipes.i++;
	}
	pipes.programs_pid = malloc(sizeof(pid_t) * (pipes.qnty_pipes + 1));
	if (pipes.programs_pid == NULL)
		error_message();
	end_pipe_exec(my_env, params, pipes, &status);
	return (status);
}

static void	child(t_my_env *my_env, char **params, t_pipe *pipes)
{
	(pipes->programs_pid)[pipes->i] = fork();
	if ((pipes->programs_pid)[pipes->i] == 0)
	{
		if (pipes->i == 0)
		{
			dup2(pipes->pipes_fd[1], 1);
			close_pipes_fd(pipes->pipes_fd, 2 * pipes->qnty_pipes);
		}
		else if (pipes->i == pipes->qnty_pipes)
		{
			dup2(pipes->pipes_fd[2 * pipes->i - 2], 0);
			close_pipes_fd(pipes->pipes_fd, 2 * pipes->qnty_pipes);
		}
		else
		{
			dup2(pipes->pipes_fd[2 * pipes->i - 2], 0);
			dup2(pipes->pipes_fd[2 * pipes->i + 1], 1);
			close_pipes_fd(pipes->pipes_fd, 2 * pipes->qnty_pipes);
		}
		exit (program_exec(my_env, params));
	}
}

static char	**get_program_params(char **params)
{
	char	**program_params;
	int		qnty_params;
	int		i;

	qnty_params = 0;
	while (params[qnty_params] != NULL
		&& ft_strncmp(params[qnty_params], "|", 2) != 0)
		qnty_params++;
	program_params = malloc(sizeof(char *) * (qnty_params + 1));
	if (program_params == NULL)
		error_message();
	i = 0;
	while (i < qnty_params)
	{
		program_params[i] = ft_strdup(params[i]);
		i++;
	}
	program_params[qnty_params] = NULL;
	return (program_params);
}

static void	end_pipe_exec(t_my_env *my_env, char **params, t_pipe pipes,
				int *status)
{
	char	**program_params;
	char	**cpy_params;

	cpy_params = params;
	pipes.i = 0;
	while (pipes.i < pipes.qnty_pipes + 1)
	{
		program_params = get_program_params(cpy_params);
		cpy_params += qnty_str(program_params) + 1;
		child(my_env, program_params, &pipes);
		free_arr_of_str(&program_params);
		pipes.i++;
	}
	close_pipes_fd(pipes.pipes_fd, 2 * pipes.qnty_pipes);
	pipes.i = 0;
	while (pipes.i < pipes.qnty_pipes + 1)
	{
		waitpid(pipes.programs_pid[pipes.i], status, 0);
		pipes.i++;
	}
}

static int	program_exec(t_my_env *my_env, char **params)
{
	t_pipe_pr	pr;

	pr.status = 0;
	pr.program_path = find_builtin_program(my_env, params[0]);
	if (ft_strncmp(params[0], "echo", 5) == 0)
		pr.status = my_echo(params);
	else if (ft_strncmp(params[0], "cd", 3) == 0)
		pr.status = my_cd(&my_env, params);
	else if (ft_strncmp(params[0], "pwd", 4) == 0)
		pr.status = my_pwd(params);
	else if (ft_strncmp(params[0], "export", 7) == 0)
		pr.status = my_export(&my_env, params);
	else if (ft_strncmp(params[0], "unset", 6) == 0)
		pr.status = my_unset(&my_env, params);
	else if (ft_strncmp(params[0], "env", 4) == 0)
		pr.status = my_environment(my_env, params);
	else if (ft_strncmp(params[0], "exit", 5) == 0)
		pr.status = my_exit(pr.status, params, &pr.is_exit);
	else if (pr.program_path != NULL)
	{
		pr.str_env = my_env_to_str(my_env);
		execve(pr.program_path, params, pr.str_env);
	}
	return (pr.status);
}
