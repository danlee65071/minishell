/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:46:19 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/21 11:46:20 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	my_pwd(char **params)
{
	int		qnty_params;
	char	*current_pwd;

	qnty_params = qnty_str(params);
	if (qnty_params > 1)
		return (1);
	current_pwd = getcwd(NULL, BUF_SIZE);
	printf("%s\n", current_pwd);
	free(current_pwd);
	return (0);
}
