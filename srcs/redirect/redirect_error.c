/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:32:02 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 08:32:03 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	redirect_error(char ***params)
{
	ft_putstr_fd("parse error near `\\n'\n", 2);
	free_arr_of_str(params);
	*params = NULL;
}
