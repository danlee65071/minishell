/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 17:29:37 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 17:29:39 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	length_new_str(const char *old_str);
static char	*process_str(char *str, t_my_env *my_env, int status);
static char	*insert_var_to_str(char *str, t_my_env *my_env, int status);
static char	*end_process_str(t_my_env *my_env, char *str, int len_new_str,
				int status);

char	**parser(t_my_env *my_env, char *input_str, int status)
{
	char	*cpy_str;
	char	**params;

	if (input_str == NULL || *input_str == '\0')
		return (NULL);
	cpy_str = process_str(input_str, my_env, status);
	params = split_params(cpy_str);
	delete_double_quotes(&params);
	free(cpy_str);
	return (params);
}

static char	*process_str(char *str, t_my_env *my_env, int status)
{
	char	*new_str;
	int		len_new_str;
	char	*tmp_str;

	if (check_quotes(str) == 0)
	{
		ft_putstr_fd("find quotes!\n", 2);
		return (NULL);
	}
	if ((ft_strlen(str) == 1 && str[0] == ' ') || ft_strlen(str) > 1)
	{
		tmp_str = str;
		str = ft_strtrim(str, " ");
		free(tmp_str);
	}
	len_new_str = length_new_str(str);
	new_str = end_process_str(my_env, str, len_new_str, status);
	return (new_str);
}

static char	*insert_var_to_str(char *str, t_my_env *my_env, int status)
{
	t_buf		buf;
	t_my_env	var_params;
	char		*new_str;
	t_index		index;

	init_buf(&index, &buf);
	while (str[index.i] != '\0')
	{
		if (str[index.i] == '$' && str[index.i + 1] == '?')
			question_mark(status, &index, &var_params, &buf);
		else if (str[index.i] == '$')
		{
			start_proc_dollar(my_env, str, &index, &var_params);
			if (proc_dollar(&var_params, &index, &buf) == 1)
				continue ;
			continue ;
		}
		else
			buf.buf[buf.buf_counter++] = str[index.i];
		index.i++;
	}
	new_str = ft_strdup(buf.buf);
	return (new_str);
}

static int	length_new_str(const char *old_str)
{
	int	len;
	int	qnty_spaces;

	len = 0;
	qnty_spaces = 0;
	while (old_str[len] != '\0')
	{
		if (is_redirect(old_str, len) == 1 || is_pipe(old_str, len) == 1)
			qnty_spaces++;
		len++;
	}
	len += qnty_spaces;
	return (len);
}

static char	*end_process_str(t_my_env *my_env, char *str, int len_new_str,
				int status)
{
	t_index	index;
	char	*tmp_str;
	char	*new_str;

	new_str = malloc(sizeof(char) * (len_new_str + 1));
	if (new_str == NULL)
		error_message();
	index.i = 0;
	index.j = 0;
	while (str[index.i] != '\0')
	{
		new_str[index.j++] = str[index.i];
		if (is_redirect(str, index.i) == 1 || is_pipe(str, index.i) == 1)
			new_str[index.j++] = ' ';
		index.i++;
	}
	new_str[len_new_str] = '\0';
	tmp_str = new_str;
	new_str = insert_var_to_str(new_str, my_env, status);
	free(tmp_str);
	return (new_str);
}
