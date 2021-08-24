/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_proc_dollar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:29:44 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 12:29:46 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	start_proc_dollar(t_my_env *my_env, char *str, t_index *index,
			t_my_env *var_params)
{
	index->i++;
	var_params->var_name = get_var_name(&str[index->i]);
	var_params->var_value
		= get_var_value_from_env(my_env, var_params->var_name);
	index->i += ft_strlen(var_params->var_name);
}
