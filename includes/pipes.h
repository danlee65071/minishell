/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:09:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 19:09:45 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPES_H
# define PIPES_H

typedef struct s_pipe
{
	int		qnty_pipes;
	int		*pipes_fd;
	pid_t	*programs_pid;
	int		i;
}	t_pipe;

typedef struct s_pipe_pr
{
	char	*program_path;
	int		status;
	char	**str_env;
	int		is_exit;
}	t_pipe_pr;

int		is_pipe(const char *str, int index);
int		find_pipes(char **params);
void	close_pipes_fd(int *pipes_fd, int pipes_fd_qnty);
int		pipe_exec(t_my_env *my_env, char **params, int *is_exit);

#endif
