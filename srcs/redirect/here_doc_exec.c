/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:11:06 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/23 09:11:08 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	here_doc_exec(char *limiter)
{
	int		fd;
	char	*input_str;

	fd = open("here_doc_file", O_WRONLY | O_CREAT | O_TRUNC, FILE_RIGHTS);
	if (fd == -1)
		error_message();
	input_str = readline("heredoc> ");
	while (ft_strncmp(input_str, limiter, ft_strlen(limiter) + 1) != 0)
	{
		ft_putstr_fd(input_str, fd);
		ft_putstr_fd("\n", fd);
		input_str = readline("heredoc> ");
	}
	close(fd);
}
