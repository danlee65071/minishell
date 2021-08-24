/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:02:31 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 17:02:34 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_my_env	*new_var(char *var_name, char *var_value)
{
	t_my_env	*new_var;

	new_var = malloc(sizeof(t_my_env));
	if (!new_var)
		return (NULL);
	new_var->var_name = var_name;
	new_var->var_value = var_value;
	new_var->next = NULL;
	return (new_var);
}
