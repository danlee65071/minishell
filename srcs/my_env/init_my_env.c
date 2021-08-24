/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_my_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:33:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:33:09 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_my_env	*init_my_env(char **env)
{
	t_env	envp;

	envp.my_env = NULL;
	envp.i = 0;
	while (env[envp.i] != NULL)
	{
		envp.chars.str_param = ft_strdup(env[envp.i]);
		if (envp.chars.str_param == NULL)
			error_message();
		envp.chars.equal_sign = ft_strchr(envp.chars.str_param, '=');
		*envp.chars.equal_sign = '\0';
		envp.chars.var_name = ft_strdup(envp.chars.str_param);
		if (envp.chars.var_name == NULL)
			error_message();
		envp.chars.equal_sign++;
		envp.chars.var_value = ft_strdup(envp.chars.equal_sign);
		if (envp.chars.var_value == NULL)
			error_message();
		envp.n_var = new_var(envp.chars.var_name, envp.chars.var_value);
		add_var_back(&envp.my_env, envp.n_var);
		free(envp.chars.str_param);
		envp.i++;
	}
	return (envp.my_env);
}
