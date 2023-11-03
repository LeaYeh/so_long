/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:14:04 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/30 22:58:15 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	_safe_calc(long long nb1, long long nb2, int sign)
{
	if (sign > 0 && nb1 > (LLONG_MAX - nb2) / 10)
		return (LLONG_MAX);
	else if (sign < 0 && (nb1 + 1) > (LLONG_MAX - nb2) / 10)
		return (LLONG_MIN);
	return (nb1 * 10 + nb2);
}

long	ft_atol(const char *str)
{
	long long	nbr;
	int			sign;
	int			i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] && ft_isdigit(str[i]) && \
			nbr != LLONG_MAX && nbr != LLONG_MIN)
		nbr = _safe_calc(nbr, str[i++] - '0', sign);
	nbr *= sign;
	return ((long) nbr);
}
