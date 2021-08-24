/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:58:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 19:58:58 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_var_name(const char *str)
{
	char	*var_name;
	int		len_var_name;
	int		i;

	len_var_name = 0;
	while (is_special_sym(str[len_var_name]) == 0 && str[len_var_name] != '\0')
		len_var_name++;
	var_name = malloc(sizeof(char) * (len_var_name + 1));
	if (var_name == NULL)
		error_message();
	i = 0;
	while (is_special_sym(str[i]) == 0 && str[i] != '\0')
	{
		var_name[i] = str[i];
		i++;
	}
	return (var_name);
}
