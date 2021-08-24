/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:43:10 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:43:11 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_message(void)
{
	ft_putstr_fd(strerror(errno), 2);
	exit(errno);
}

int	qnty_str(char **arr)
{
	int	count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	return (count);
}

int	is_special_sym(char c)
{
	return (c == '\'' || c == '\"' || c == '=' || c == '\\' || c == '/'
		|| c == ';' || c == ',' || c == '#' || c == '$' || c == '&' || c == '('
		|| c == ')' || c == '%' || c == '[' || c == ']' || c == '~' || c == ':'
		|| c == '*' || c == '+' || c == '-' || c == '!' || c == '?' || c == '{'
		|| c == '}' || c == '^' || c == '@' || c == '<' || c == '>'
		|| c == ' ');
}

void	free_arr_of_str(char ***arr_str)
{
	int	i;

	if (*arr_str == NULL)
		return ;
	i = 0;
	while ((*arr_str)[i] != NULL)
	{
		free((*arr_str)[i]);
		i++;
	}
	free(*arr_str);
}
