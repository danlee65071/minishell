/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:44:17 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 16:44:18 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	error_message(void);
int		qnty_str(char **arr);
int		is_special_sym(char c);
void	free_arr_of_str(char ***arr_str);

#endif
