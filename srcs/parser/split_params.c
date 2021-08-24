/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 21:46:47 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 21:46:48 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_space(const char *ptr_space, const char *str);
static int	qnty_params(char *str);
static char	*split_loop(char *str, t_index *index, char ***params,
				char **cpy_str);

char	**split_params(char *str)
{
	char	**params;
	char	*cpy_str;
	char	*start_cpy_str;
	int		len_params;
	t_index	index;

	if (str == NULL)
		return (NULL);
	len_params = qnty_params(str);
	params = malloc(sizeof(char *) * (len_params + 1));
	if (params == NULL)
		error_message();
	cpy_str = ft_strdup(str);
	index.i = 0;
	index.j = 0;
	start_cpy_str = split_loop(str, &index, &params, &cpy_str);
	params[index.j] = ft_strdup(cpy_str);
	params[len_params] = NULL;
	free(start_cpy_str);
	return (params);
}

static int	qnty_params(char *str)
{
	int	qnty_spaces;
	int	i;

	qnty_spaces = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != ' '
			&& check_space(&(str[i]), str) == 1)
			qnty_spaces++;
		i++;
	}
	return (qnty_spaces + 1);
}

static int	check_space(const char *ptr_space, const char *str)
{
	int		first_quote;
	int		second_quote;
	int		i;

	first_quote = 0;
	i = 0;
	while (ptr_space + i != str)
	{
		if (*(ptr_space + i) == '"')
			first_quote++;
		i--;
	}
	if (*(ptr_space + i) == '"')
		first_quote++;
	second_quote = 0;
	i = 0;
	while (*(ptr_space + i) != '\0')
	{
		if (*(ptr_space + i) == '"')
			second_quote++;
		i++;
	}
	if (first_quote % 2 == 0 || (first_quote % 2 != 0 && second_quote == 0))
		return (1);
	return (0);
}

static char	*split_loop(char *str, t_index *index, char ***params,
				char **cpy_str)
{
	char	*start_cpy_str;

	start_cpy_str = *cpy_str;
	while (str[index->i] != '\0')
	{
		if (str[index->i] == ' ' && str[index->i + 1] != ' '
			&& check_space(&(str[index->i]), str) == 1)
		{
			start_cpy_str[index->i] = '\0';
			if (ft_strlen(*cpy_str) == 1)
				(*params)[index->j++] = ft_strdup(*cpy_str);
			else
				(*params)[index->j++] = ft_strtrim(*cpy_str, " ");
			*cpy_str = start_cpy_str + index->i + 1;
		}
		index->i++;
	}
	return (start_cpy_str);
}
