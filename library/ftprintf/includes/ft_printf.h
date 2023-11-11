/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:12:08 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:50:21 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

int		ft_print_string(int fd, char *s);
int		ft_print_char(int fd, char c);
int		ft_print_int(int fd, int n);
int		ft_print_uint(int fd, unsigned int n);
int		ft_print_addr(int fd, unsigned long int n);
int		ft_print_hex(int fd, unsigned int n, bool is_upper);
int		ft_printf(int fd, const char *format, ...);
int		ft_dprintf(int fd, const char *format, ...);
char	*copy_char(char c);
void	lst_add_char(t_list **lst, char *ch);
void	handle_char(t_list **ch_arr, char *c);
void	handle_string(t_list **ch_arr, char *s);
void	handle_int(t_list **ch_arr, int n);
int		ft_sprintf(char **store_str, char *format, ...);

#endif