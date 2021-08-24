/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_value_from_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:24:42 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 19:24:43 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_var_value_from_env(t_my_env *my_env, char *var_name)
{
	while (my_env != NULL)
	{
		if (ft_strncmp(my_env->var_name, var_name,
				ft_strlen(var_name) + 1) == 0)
			return (my_env->var_value);
		my_env = my_env->next;
	}
	return (NULL);
}
