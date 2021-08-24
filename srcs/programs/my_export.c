/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 06:56:15 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 06:56:16 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void		add_var_to_my_env(t_my_env **my_env, char *params);
static int		is_var_in_env(t_my_env *my_env, char *params);

int	my_export(t_my_env **my_env, char **params)
{
	int			qnty_params;
	t_my_env	*sorted_env;
	int			i;

	qnty_params = qnty_str(params);
	if (qnty_params == 1)
	{
		sorted_env = cpy_my_env(*my_env);
		sorted_env = sort_env(sorted_env);
		print_my_env(sorted_env);
		free_my_env(&sorted_env);
	}
	else
	{
		i = 1;
		while (params[i] != NULL)
		{
			if (is_var_in_env(*my_env, params[i]) == 1)
				change_var_value(my_env, params[i]);
			else
				add_var_to_my_env(my_env, params[i]);
			i++;
		}
	}
	return (0);
}

static void	add_var_to_my_env(t_my_env **my_env, char *params)
{
	t_add	add;

	add.split_params = ft_split(params, '=');
	add.qnty_params = qnty_str(add.split_params);
	if (add.qnty_params < 2)
		return ;
	add.cpy_my_env = *my_env;
	add.penultimate_var = add.cpy_my_env;
	while (add.cpy_my_env->next != NULL)
	{
		add.penultimate_var = add.cpy_my_env;
		add.cpy_my_env = add.cpy_my_env->next;
	}
	add.last_variable = last_var(*my_env);
	add.var_params.var_name = (add.split_params)[0];
	add.var_params.var_value = (add.split_params)[1];
	add.new_variable = new_var(ft_strdup(add.var_params.var_name),
			ft_strdup(add.var_params.var_value));
	add_var_back(my_env, add.new_variable);
	add.penultimate_var->next = add.new_variable;
	add.new_variable->next = add.last_variable;
	add.last_variable->next = NULL;
	free_arr_of_str(&(add.split_params));
}

static int	is_var_in_env(t_my_env *my_env, char *params)
{
	char	**split_params;
	char	*var_name;
	int		qnty_params;

	split_params = ft_split(params, '=');
	qnty_params = qnty_str(split_params);
	if (qnty_params < 2)
		return (0);
	var_name = split_params[0];
	if (get_var_value_from_env(my_env, var_name) == NULL)
		return (0);
	free_arr_of_str(&split_params);
	return (1);
}

void	change_var_value(t_my_env **my_env, char *params)
{
	t_my_env	var;
	t_my_env	*cpy_my_env;
	t_my_env	*change_var;
	char		**split_params;

	split_params = ft_split(params, '=');
	var.var_name = split_params[0];
	var.var_value = split_params[1];
	cpy_my_env = *my_env;
	while (cpy_my_env != NULL)
	{
		if (ft_strncmp(cpy_my_env->var_name, var.var_name,
				ft_strlen(var.var_name) + 1) == 0)
			change_var = cpy_my_env;
		cpy_my_env = cpy_my_env->next;
	}
	free(change_var->var_value);
	change_var->var_value = ft_strdup(var.var_value);
	free_arr_of_str(&split_params);
}
