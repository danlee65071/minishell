/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:47:22 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 09:47:24 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_pwd(int qnty_params, char **params);

int	my_environment(t_my_env *my_env, char **params)
{
	int		qnty_params;
	char	*pwd;

	qnty_params = qnty_str(params);
	if (qnty_params == 1)
		print_my_env(my_env);
	else if (check_pwd(qnty_params, params))
	{
		pwd = getcwd(NULL, BUF_SIZE);
		printf("%s\n", pwd);
		free(pwd);
	}
	else if (qnty_params > 2 && (ft_strncmp(params[1], "PWD", 4) == 0
			|| ft_strncmp(params[1], "pwd", 4) == 0))
	{
		ft_putstr_fd("usage: pwd [-L | -P]\n", 2);
		return (1);
	}
	else
	{
		ft_putstr_fd("env: too many arguments!\n", 2);
		return (1);
	}
	return (0);
}

static int	check_pwd(int qnty_params, char **params)
{
	return ((qnty_params == 2 && (ft_strncmp(params[1], "PWD", 4) == 0
				|| ft_strncmp(params[1], "pwd", 4) == 0)) || (qnty_params == 3
			&& (ft_strncmp(params[1], "PWD", 4) == 0 || ft_strncmp(params[1],
					"pwd", 4) == 0) && (ft_strncmp(params[2], "-L", 3) == 0
				|| ft_strncmp(params[2], "-P", 3) == 0)));
}
