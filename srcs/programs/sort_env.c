/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:13:16 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 10:13:17 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	proc_else(t_my_env **current, t_my_env **node, t_my_env *new_start);

t_my_env	*sort_env(t_my_env *my_env)
{
	t_my_env	*new_start;
	t_my_env	*node;
	t_my_env	*current;

	new_start = NULL;
	while (my_env != NULL)
	{
		node = my_env;
		my_env = my_env->next;
		if (new_start == NULL || ft_strncmp(node->var_name, new_start->var_name,
				ft_strlen(node->var_name) + ft_strlen(new_start->var_name)) < 0)
		{
			node->next = new_start;
			new_start = node;
		}
		else
			proc_else(&current, &node, new_start);
	}
	return (new_start);
}

static void	proc_else(t_my_env **current, t_my_env **node, t_my_env *new_start)
{
	*current = new_start;
	while ((*current)->next != NULL && ft_strncmp((*node)->var_name,
			(*current)->next->var_name, ft_strlen((*node)->var_name)
			+ ft_strlen((*current)->next->var_name)) > 0)
		(*current) = (*current)->next;
	(*node)->next = (*current)->next;
	(*current)->next = (*node);
}
