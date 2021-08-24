/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_my_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 07:28:47 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 07:28:48 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_my_env	*cpy_my_env(t_my_env *my_env)
{
	t_my_env	*cpy_env;
	t_my_env	*cpy_var;

	cpy_env = NULL;
	while (my_env != NULL)
	{
		cpy_var = new_var(ft_strdup(my_env->var_name),
				ft_strdup(my_env->var_value));
		add_var_back(&cpy_env, cpy_var);
		my_env = my_env->next;
	}
	return (cpy_env);
}
