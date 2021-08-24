/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:26:04 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 12:26:05 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	qnty_vars_in_my_env(t_my_env *my_env);

char	**my_env_to_str(t_my_env *my_env)
{
	char		**str_env;
	char		*tmp_str;
	int			qnty_vars;
	t_my_env	*cpy_my_env;
	int			i;

	cpy_my_env = my_env;
	qnty_vars = qnty_vars_in_my_env(cpy_my_env);
	str_env = malloc(sizeof(char *) * (qnty_vars + 1));
	i = 0;
	while (cpy_my_env != NULL)
	{
		str_env[i] = ft_strjoin(cpy_my_env->var_name, "=");
		tmp_str = str_env[i];
		str_env[i] = ft_strjoin(str_env[i], cpy_my_env->var_value);
		free(tmp_str);
		i++;
		cpy_my_env = cpy_my_env->next;
	}
	str_env[qnty_vars] = NULL;
	return (str_env);
}

static int	qnty_vars_in_my_env(t_my_env *my_env)
{
	int	qnty_vars;

	qnty_vars = 0;
	while (my_env != NULL)
	{
		qnty_vars++;
		my_env = my_env->next;
	}
	return (qnty_vars);
}
