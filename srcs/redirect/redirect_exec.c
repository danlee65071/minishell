/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:01:57 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 21:01:59 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_redirect(char **params);
static char	*get_file_name(char **params);
static char	**get_new_params(char **params);
static char	**init_new_params(char **params, int *len_new_params,
				t_index *index);

int	redirect_exec(char ***params, int *old_std_in, int *old_std_out)
{
	int		fd;
	char	*file_name;
	char	**new_params;
	char	*redirect;

	if (params == NULL)
		return (0);
	if (check_redirect(*params) == 0)
		redirect_error(params);
	if (check_redirect(*params) == 0)
		return (0);
	redirect = find_redirect(*params);
	file_name = get_file_name(*params);
	fd = choose_redirect(redirect, file_name);
	if (fd == -1)
		fd_error(params, file_name);
	if (fd == -1)
		return (0);
	dup_std(redirect, fd, old_std_in, old_std_out);
	close(fd);
	new_params = get_new_params(*params);
	free_arr_of_str(params);
	*params = new_params;
	return (1);
}

static int	check_redirect(char **params)
{
	if (ft_strncmp(params[qnty_str(params) - 1], "<", 2) == 0
		|| ft_strncmp(params[qnty_str(params) - 1], ">", 2) == 0
		|| ft_strncmp(params[qnty_str(params) - 1], ">>", 3) == 0
		|| ft_strncmp(params[qnty_str(params) - 1], "<<", 3) == 0)
		return (0);
	return (1);
}

static char	*get_file_name(char **params)
{
	int	i;

	i = 0;
	while (params[i] != NULL)
	{
		if (ft_strncmp(params[i], "<", 2) == 0
			|| ft_strncmp(params[i], ">", 2) == 0
			|| ft_strncmp(params[i], ">>", 3) == 0
			|| ft_strncmp(params[i], "<<", 3) == 0)
			return (params[i + 1]);
		i++;
	}
	return (NULL);
}

static char	**get_new_params(char **params)
{
	char	**new_params;
	int		len_new_params;
	t_index	index;

	new_params = init_new_params(params, &len_new_params, &index);
	while (params[index.i] != NULL)
	{
		if (ft_strncmp(params[index.i], "<", 2) == 0
			|| ft_strncmp(params[index.i], ">", 2) == 0
			|| ft_strncmp(params[index.i], ">>", 3) == 0
			|| ft_strncmp(params[index.i], "<<", 3) == 0)
		{
			index.i += 2;
			break ;
		}
		new_params[index.j++] = ft_strdup(params[index.i]);
		index.i++;
	}
	while (params[index.i] != NULL)
	{
		new_params[index.j++] = ft_strdup(params[index.i]);
		index.i++;
	}
	return (new_params);
}

static char	**init_new_params(char **params, int *len_new_params,
				t_index *index)
{
	char	**new_params;

	*len_new_params = qnty_str(params) - 2;
	new_params = malloc(sizeof(char *) * (*len_new_params + 1));
	if (new_params == NULL)
		error_message();
	index->i = 0;
	index->j = 0;
	new_params[*len_new_params] = NULL;
	return (new_params);
}
