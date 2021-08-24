/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:08:39 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 17:08:41 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_my_env	*last_var(t_my_env *my_env)
{
	if (my_env)
	{
		while (my_env->next)
			my_env = my_env->next;
	}
	return (my_env);
}
