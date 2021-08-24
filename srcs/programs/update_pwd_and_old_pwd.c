/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_pwd_and_old_pwd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 09:08:12 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 09:08:13 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	update_old_pwd(t_my_env **my_env, char **old_pwd)
{
	char	*tmp_str;

	*old_pwd = getcwd(NULL, BUF_SIZE);
	tmp_str = *old_pwd;
	*old_pwd = ft_strjoin("OLDPWD=", *old_pwd);
	free(tmp_str);
	change_var_value(my_env, *old_pwd);
}

void	update_pwd(t_my_env **my_env, char **pwd)
{
	char	*tmp_str;

	*pwd = getcwd(NULL, BUF_SIZE);
	tmp_str = *pwd;
	*pwd = ft_strjoin("PWD=", *pwd);
	free(tmp_str);
	change_var_value(my_env, *pwd);
}
