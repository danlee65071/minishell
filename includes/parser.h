/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 20:41:09 by hcharlsi          #+#    #+#             */
/*   Updated: 2021/08/20 20:41:10 by hcharlsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

char	**parser(t_my_env *my_env, char *input_str, int status);
char	*get_var_name(const char *str);
int		check_quotes(char *str);
char	**split_params(char *str);
char	*get_str_without_double_quotes(char *str, const char *first_quote,
			const char *second_quote);
void	delete_double_quotes(char ***params);

#endif
