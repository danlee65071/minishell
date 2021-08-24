/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:06:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 17:06:38 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_var_back(t_my_env **my_env, t_my_env *new_var)
{
	t_my_env	*tmp;

	if (my_env)
	{
		if (*my_env == NULL)
			*my_env = new_var;
		else
		{
			tmp = last_var(*(my_env));
			tmp->next = new_var;
		}
	}
}
