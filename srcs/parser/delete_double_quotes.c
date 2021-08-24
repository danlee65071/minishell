/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_double_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 23:01:51 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 23:01:53 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_double_quotes(char ***params)
{
	char	*tmp_str;
	char	*first_quote;
	char	*second_quote;
	int		i;

	i = 0;
	while ((*params)[i] != NULL)
	{
		first_quote = ft_strchr((*params)[i], '"');
		second_quote = ft_strrchr((*params)[i], '"');
		if (first_quote != second_quote)
		{
			tmp_str = (*params)[i];
			(*params)[i] = get_str_without_double_quotes((*params)[i],
					first_quote, second_quote);
			free(tmp_str);
		}
		i++;
	}
}
