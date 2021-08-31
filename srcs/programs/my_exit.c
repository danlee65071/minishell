/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:26:05 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 11:26:06 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	my_exit(int status, char **params, int *is_exit)
{
	int	qnty_params;
	int	exit_status;

	qnty_params = qnty_str(params);
	if (qnty_params > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return (1);
	}
	*is_exit = 1;
	if (qnty_params == 2)
	{
		exit_status = ft_atoi(params[1]);
		return (exit_status);
	}
	printf("exit\n");
	return (status);
}
