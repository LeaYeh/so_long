/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:52:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/10/31 19:12:50 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

int	ft_in_substr(const char c, const char *sub)
{
	int	i;

	i = 0;
	while (sub[i])
	{
		if (sub[i] == c)
			return (true);
		i++;
	}
	return (false);
}

long long int	ft_pow(int base, int n)
{
	long long int	ret;

	ret = 1;
	while (n > 0)
	{
		ret *= base;
		n--;
	}
	return (ret);
}
