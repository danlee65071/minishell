/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin_program.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 11:44:16 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/22 11:44:17 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_params(t_my_env *my_env, t_pr *pr);
static void	get_program_path(char *program_name, t_pr *pr);
static void	end_loop(t_pr *pr);

char	*find_builtin_program(t_my_env *my_env, char *program_name)
{
	t_pr	pr;

	init_params(my_env, &pr);
	while (pr.programs_dirs[pr.i] != NULL)
	{
		pr.dir = opendir(pr.programs_dirs[pr.i]);
		if (pr.dir == NULL)
			pr.i++;
		if (pr.dir == NULL)
			continue ;
		pr.file = readdir(pr.dir);
		while (pr.file != NULL)
		{
			if (ft_strncmp(pr.file->d_name, program_name,
					ft_strlen(program_name) + 1) == 0)
			{
				get_program_path(program_name, &pr);
				return (pr.program_path);
			}
			pr.file = readdir(pr.dir);
		}
		end_loop(&pr);
	}
	return (pr.program_path);
}

static void	init_params(t_my_env *my_env, t_pr *pr)
{
	pr->program_path = NULL;
	pr->programs_dirs = ft_split(get_var_value_from_env(my_env, "PATH"), ':');
	pr->i = 0;
}

static void	get_program_path(char *program_name, t_pr *pr)
{
	pr->program_path = ft_strjoin(pr->programs_dirs[pr->i], "/");
	pr->tmp_str = pr->program_path;
	pr->program_path = ft_strjoin(pr->program_path, program_name);
	free(pr->tmp_str);
}

static void	end_loop(t_pr *pr)
{
	if (closedir(pr->dir) == -1)
		error_message();
	pr->i++;
}
