/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:29:01 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 08:29:03 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fd_error(char ***params, char *file_name)
{
	ft_putstr_fd("permission denied: ", 2);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd("\n", 2);
	free_arr_of_str(params);
	*params = NULL;
}
