/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 06:59:05 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/21 06:59:07 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	print_params(char **params);

int	my_echo(char **params)
{
	if (qnty_str(params) == 1)
		printf("\n");
	else if (ft_strncmp(params[1], "-n", 3) == 0)
		print_params(params + 2);
	else
	{
		print_params(params + 1);
		printf("\n");
	}
	return (0);
}

static void	print_params(char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		printf("%s", params[i]);
		if (params[i + 1] != NULL)
			printf(" ");
		i++;
	}
}
