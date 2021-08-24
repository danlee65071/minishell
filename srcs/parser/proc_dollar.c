/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_dollar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:15:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 13:15:43 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	proc_dollar(t_my_env *var_params, t_index *index, t_buf *buf)
{
	if (var_params->var_value == NULL)
		free(var_params->var_name);
	if (var_params->var_value == NULL)
		return (1);
	index->j = 0;
	while (var_params->var_value[index->j] != '\0')
		buf->buf[buf->buf_counter++] = var_params->var_value[index->j++];
	free(var_params->var_name);
	return (0);
}
