/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recovery_std_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:22:04 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/23 08:22:06 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	recovery_std_fd(int old_std_in, int old_std_out)
{
	dup2(old_std_in, STDIN_FILENO);
	close(old_std_in);
	dup2(old_std_out, STDOUT_FILENO);
	close(old_std_out);
}
