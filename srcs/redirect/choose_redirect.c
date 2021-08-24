/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_redirect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:16:50 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/24 08:16:51 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	choose_redirect(char *redirect, char *file_name)
{
	int	fd;

	fd = 0;
	if (ft_strncmp(redirect, "<", 2) == 0)
		fd = open(file_name, O_RDONLY);
	else if (ft_strncmp(redirect, ">", 2) == 0)
		fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, FILE_RIGHTS);
	else if (ft_strncmp(redirect, ">>", 3) == 0)
		fd = open(file_name, O_CREAT | O_APPEND | O_WRONLY, FILE_RIGHTS);
	else if (ft_strncmp(redirect, "<<", 3) == 0)
	{
		here_doc_exec(file_name);
		fd = open("here_doc_file", O_RDONLY);
	}
	return (fd);
}
