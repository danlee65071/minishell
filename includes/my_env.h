/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:31:41 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:31:42 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ENV_H
# define MY_ENV_H

typedef struct s_my_env
{
	char			*var_name;
	char			*var_value;
	struct s_my_env	*next;
}	t_my_env;

typedef struct s_support_chars
{
	char		*equal_sign;
	char		*var_name;
	char		*var_value;
	char		*str_param;
}	t_support_chars;

typedef struct s_env
{
	t_my_env		*my_env;
	t_my_env		*n_var;
	t_support_chars	chars;
	int				i;
}	t_env;

t_my_env	*new_var(char *var_name, char *var_value);
t_my_env	*last_var(t_my_env *my_env);
void		add_var_back(t_my_env **my_env, t_my_env *new_var);
t_my_env	*init_my_env(char **env);
char		*get_var_value_from_env(t_my_env *my_env, char *var_name);
void		print_my_env(t_my_env *my_env);
t_my_env	*cpy_my_env(t_my_env *my_env);
void		free_my_env(t_my_env **my_env);
char		**my_env_to_str(t_my_env *my_env);

#endif
