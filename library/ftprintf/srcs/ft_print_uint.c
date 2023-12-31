/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 21:47:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/06 17:31:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_utils.h"

int	ft_print_uint(int fd, unsigned int n)
{
	char	*num_str;
	int		len;

	num_str = ft_utoa(n);
	len = ft_strlen(num_str);
	write(fd, num_str, len);
	free(num_str);
	return (len);
}
