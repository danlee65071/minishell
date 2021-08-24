/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:25:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 16:25:30 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_pipes(char **params)
{
	int	i;
	int	qnty_pipes;

	if (params == NULL)
		return (0);
	qnty_pipes = 0;
	i = 0;
	while (params[i] != NULL)
	{
		if (ft_strncmp(params[i], "|", 2) == 0)
			qnty_pipes++;
		i++;
	}
	return (qnty_pipes);
}
