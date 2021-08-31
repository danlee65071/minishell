/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_my_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 07:34:24 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 07:34:26 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_my_env(t_my_env **my_env)
{
	t_my_env	*tmp_env;

	while (*my_env != NULL)
	{
		tmp_env = *my_env;
		(*my_env) = (*my_env)->next;
		free(tmp_env->var_name);
		free(tmp_env->var_value);
		free(tmp_env);
	}
}
