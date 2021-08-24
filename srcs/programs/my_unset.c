/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 09:26:21 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 09:26:23 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	delete_var(t_my_env **my_env, char *var_name);
static void	proc_del_var(t_my_env **del_var, t_my_env **prev_del_var,
				t_my_env *cpy_my_env);

int	my_unset(t_my_env **my_env, char **params)
{
	int	qnty_params;
	int	i;

	qnty_params = qnty_str(params);
	if (qnty_params == 1)
	{
		ft_putstr_fd("unset: not enough arguments\n", 2);
		return (1);
	}
	i = 1;
	while (params[i] != NULL)
	{
		delete_var(my_env, params[i]);
		i++;
	}
	return (0);
}

static void	delete_var(t_my_env **my_env, char *var_name)
{
	t_del		del;
	t_my_env	*cpy_my_env;

	if (ft_strncmp((*my_env)->var_name, var_name, ft_strlen(var_name) + 1) == 0)
	{
		free((*my_env)->var_name);
		free((*my_env)->var_value);
		free(*my_env);
		(*my_env) = (*my_env)->next;
		return ;
	}
	cpy_my_env = (*my_env)->next;
	del.prev_del_var = (*my_env);
	while (cpy_my_env != NULL)
	{
		if (ft_strncmp(cpy_my_env->var_name, var_name,
				ft_strlen(var_name) + 1) == 0)
		{
			proc_del_var(&del.del_var, &del.prev_del_var, cpy_my_env);
			return ;
		}
		del.prev_del_var = cpy_my_env;
		cpy_my_env = cpy_my_env->next;
	}
}

static void	proc_del_var(t_my_env **del_var, t_my_env **prev_del_var,
				t_my_env *cpy_my_env)
{
	*del_var = cpy_my_env;
	(*prev_del_var)->next = (*del_var)->next;
	free((*del_var)->var_name);
	free((*del_var)->var_value);
	free(*del_var);
}
