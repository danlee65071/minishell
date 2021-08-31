/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:03:13 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:03:15 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <setjmp.h>
# include "libft.h"
# include "my_env.h"
# include "redirect.h"
# include "pipes.h"
# include "utils.h"
# include "parser.h"

# define BUF_SIZE 1024
# define FILE_RIGHTS 0640

typedef struct s_index
{
	int		i;
	int		j;
}	t_index;

typedef struct s_buf
{
	char		buf[BUF_SIZE];
	int			buf_counter;
}	t_buf;

typedef struct s_minishell
{
	char			*input_str;
	char			**params;
	t_my_env		*my_env;
	int				status;
	int				is_exit;
	int				old_std_in;
	int				old_std_out;
	struct termios	new_term;
	struct termios	old_term;
}	t_minishell;

typedef struct s_cd
{
	char	*absolute_path;
	int		qnty_params;
	char	*old_pwd;
	char	*pwd;
}	t_cd;

typedef struct s_del
{
	t_my_env	*del_var;
	t_my_env	*prev_del_var;
}	t_del;

typedef struct s_pr
{
	char			*program_path;
	char			*tmp_str;
	char			**programs_dirs;
	DIR				*dir;
	struct dirent	*file;
	int				i;
}	t_pr;

typedef struct s_add
{
	t_my_env	var_params;
	t_my_env	*new_variable;
	t_my_env	*penultimate_var;
	t_my_env	*last_variable;
	t_my_env	*cpy_my_env;
	char		**split_params;
	int			qnty_params;
}	t_add;

sigjmp_buf		g_ctrl_buf;

int			program_execution(t_my_env **my_env, char **params, int *is_exit);
int			my_echo(char **params);
void		update_old_pwd(t_my_env **my_env, char **old_pwd);
void		update_pwd(t_my_env **my_env, char **pwd);
int			my_cd(t_my_env **my_env, char **params);
int			my_pwd(char **params);
void		change_var_value(t_my_env **my_env, char *params);
t_my_env	*sort_env(t_my_env *my_env);
int			my_export(t_my_env **my_env, char **params);
int			my_unset(t_my_env **my_env, char **params);
int			my_environment(t_my_env *my_env, char **params);
int			my_exit(int status, char **params, int *is_exit);
char		*find_builtin_program(t_my_env *my_env, char *program_name);
int			builtin_program_exec(t_my_env *my_env, char **params,
				char *program_path);
char		*get_absolute_path(char *path);
void		question_mark(int status, t_index *index, t_my_env *var_params,
				t_buf *buf);
void		init_buf(t_index *index, t_buf *buf);
void		start_proc_dollar(t_my_env *my_env, char *str, t_index *index,
				t_my_env *var_params);
int			proc_dollar(t_my_env *var_params, t_index *index, t_buf *buf);
int			bin_exec(t_my_env **my_env, char **params);

#endif
