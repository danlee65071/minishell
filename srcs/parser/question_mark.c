/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   question_mark.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:22:28 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 12:22:29 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	question_mark(int status, t_index *index, t_my_env *var_params,
			t_buf *buf)
{
	index->i += 2;
	var_params->var_value = ft_itoa(status);
	index->j = 0;
	while (var_params->var_value[index->j] != '\0')
		buf->buf[buf->buf_counter++] = var_params->var_value[index->j++];
	free(var_params->var_value);
}
