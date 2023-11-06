/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:52:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/06 17:27:31 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

bool	ft_has_subset(const char *s, const char *subset)
{
	int	i;
	int	j;

	if (!s || !subset)
		return (false);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (subset[j])
		{
			if (s[i] == subset[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
