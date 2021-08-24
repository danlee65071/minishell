/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:02:23 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 19:02:24 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redirect(const char *str, int index)
{
	return (((str[index] == '<' && str[index + 1] != ' '
				&& str[index + 1] != '\0' && str[index + 1] != '<')
			 || (str[index] != '<' && str[index + 1] == '<'))
		|| ((str[index] == '>' && str[index + 1] != ' '
				 && str[index + 1] != '\0' && str[index + 1] != '>')
			|| (str[index] != '>' && str[index + 1] == '>')));
}
