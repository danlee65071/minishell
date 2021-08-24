/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:58:29 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 20:58:31 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_signle_quote(char *str);
static int	check_double_quote(char *str);

int	check_quotes(char *str)
{
	return (check_signle_quote(str) * check_double_quote(str));
}

static int	check_signle_quote(char *str)
{
	char	*first_quote;
	char	*second_quote;

	first_quote = ft_strchr(str, '\'');
	second_quote = ft_strrchr(str, '\'');
	if (first_quote == second_quote)
		return (1);
	return (0);
}

static int	check_double_quote(char *str)
{
	char	*first_quote;
	char	*second_quote;
	char	*dollar_sign;

	first_quote = ft_strchr(str, '"');
	second_quote = ft_strrchr(str, '"');
	if (first_quote != NULL)
		dollar_sign = ft_strchr(first_quote, '$');
	if (first_quote == second_quote
		|| (first_quote != second_quote && dollar_sign < second_quote
			&& dollar_sign != NULL))
		return (1);
	return (0);
}

char	*get_str_without_double_quotes(char *str, const char *first_quote,
											 const char *second_quote)
{
	char	*new_str;
	int		len_new_str;
	t_index	index;

	len_new_str = ft_strlen(str) - 2;
	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (new_str == NULL)
		error_message();
	index.i = 0;
	index.j = 0;
	while (str[index.i] != '\0')
	{
		if (&(str[index.i]) == first_quote || &(str[index.i]) == second_quote)
			index.i++;
		new_str[index.j++] = str[index.i];
		index.i++;
	}
	new_str[len_new_str] = '\0';
	return (new_str);
}
