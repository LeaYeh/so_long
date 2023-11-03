/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:12:08 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/02 18:15:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

int	ft_printf(int fd, const char *format, ...);
int	ft_print_string(int fd, char *s);
int	ft_print_char(int fd, char c);
int	ft_print_int(int fd, int n);
int	ft_print_uint(int fd, unsigned int n);
int	ft_print_addr(int fd, unsigned long int n);
int	ft_print_hex(int fd, unsigned int n, bool is_upper);
int	ft_dprintf(int fd, const char *format, ...);

#endif