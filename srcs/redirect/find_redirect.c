/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:54:03 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 20:54:04 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*find_redirect(char **params)
{
	int		i;

	if (params == NULL)
		return (NULL);
	i = 0;
	while (params[i] != NULL)
	{
		if (ft_strncmp(params[i], "<", 2) == 0
			|| ft_strncmp(params[i], ">", 2) == 0
			   || ft_strncmp(params[i], ">>", 3) == 0
			|| ft_strncmp(params[i], "<<", 3) == 0)
			return (params[i]);
		i++;
	}
	return (NULL);
}
