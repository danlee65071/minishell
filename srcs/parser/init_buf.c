/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:27:08 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 12:27:09 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_buf(t_index *index, t_buf *buf)
{
	ft_bzero(buf->buf, BUF_SIZE);
	index->i = 0;
	buf->buf_counter = 0;
}
