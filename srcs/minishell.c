/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:07:26 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:07:28 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	minishell_init(int argc, char **argv, char **env,
				t_minishell *minishell);
static void	process_signals(int signal);
static void	loop_routine(t_minishell *minishell);

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;

	minishell_init(argc, argv, env, &minishell);
	signal(SIGINT, process_signals);
	while (minishell.is_exit == 0)
	{
		minishell.old_std_out = dup(STDOUT_FILENO);
		minishell.old_std_in = dup(STDIN_FILENO);
		minishell.input_str = readline("minishell: ");
		if (minishell.input_str == NULL)
			printf("\b\bexit\n");
		if (minishell.input_str == NULL)
			break ;
		loop_routine(&minishell);
	}
	free_my_env(&(minishell.my_env));
	rl_clear_history();
	tcsetattr(STDIN_FILENO, TCSANOW, &minishell.old_term);
	return (minishell.status % 255);
}

static void	process_signals(int signal)
{
	if (signal == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		printf("  \n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	minishell_init(int argc, char **argv, char **env,
				t_minishell *minishell)
{
	t_my_env	*head;
	char		*tmp_str;

	(void)argc;
	(void)argv;
	tcgetattr(STDIN_FILENO, &minishell->old_term);
	minishell->new_term = minishell->old_term;
	minishell->new_term.c_cc[VQUIT] = _POSIX_VDISABLE - 1;
	tcsetattr(STDIN_FILENO, TCSANOW, &minishell->new_term);
	minishell->status = 0;
	minishell->is_exit = 0;
	minishell->my_env = init_my_env(env);
	head = minishell->my_env;
	while (head != NULL)
	{
		if (ft_strncmp(head->var_name, "SHLVL", 6) == 0)
		{
			tmp_str = head->var_value;
			head->var_value = ft_itoa(ft_atoi(head->var_value) + 1);
			free(tmp_str);
			break ;
		}
		head = head->next;
	}
	minishell->input_str = NULL;
}

static void	loop_routine(t_minishell *minishell)
{
	if (minishell->input_str[0] != '\0')
		add_history(minishell->input_str);
	minishell->params = parser(minishell->my_env, minishell->input_str,
			minishell->status);
	while (find_redirect(minishell->params) != NULL)
		redirect_exec(&minishell->params, &minishell->old_std_in,
			&minishell->old_std_out);
	if (find_pipes(minishell->params) > 0)
		minishell->status = pipe_exec(minishell->my_env, minishell->params,
				&minishell->is_exit);
	else
		minishell->status = program_execution(&minishell->my_env,
				minishell->params, &minishell->is_exit);
	free_arr_of_str(&minishell->params);
	recovery_std_fd(minishell->old_std_in, minishell->old_std_out);
	unlink("here_doc_file");
}
