/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:49:40 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 16:49:41 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_pipes_fd(int *pipes_fd, int pipes_fd_qnty)
{
	int	i;

	i = -1;
	while (++i < pipes_fd_qnty)
		close(pipes_fd[i]);
}
