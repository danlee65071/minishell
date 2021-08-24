/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_std.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:21:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 08:21:43 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_std(char *redirect, int fd, int *old_std_in, int *old_std_out)
{
	if (ft_strncmp(redirect, "<", 2) == 0
		|| ft_strncmp(redirect, "<<", 3) == 0)
	{
		*old_std_in = dup(STDIN_FILENO);
		dup2(fd, STDIN_FILENO);
	}
	else if (ft_strncmp(redirect, ">", 2) == 0
		|| ft_strncmp(redirect, ">>", 3) == 0)
	{
		*old_std_out = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
	}
}
