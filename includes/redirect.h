/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 19:04:38 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 19:04:40 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

int		is_redirect(const char *str, int index);
char	*find_redirect(char **params);
int		redirect_exec(char ***params, int *old_std_in, int *old_std_out);
void	recovery_std_fd(int old_std_in, int old_std_out);
void	here_doc_exec(char *limiter);
int		choose_redirect(char *redirect, char *file_name);
void	dup_std(char *redirect, int fd, int *old_std_in, int *old_std_out);
void	fd_error(char ***params, char *file_name);
void	redirect_error(char ***params);

#endif
