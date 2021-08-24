/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_my_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 07:15:59 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 07:16:00 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_my_env(t_my_env *my_env)
{
	while (my_env != NULL)
	{
		printf("%s=%s\n", my_env->var_name, my_env->var_value);
		my_env = my_env->next;
	}
}
