/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:12:02 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/03 23:34:54 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_array_len(void **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

void	remove_last_newline(char **s)
{
	int	len;

	len = ft_strlen(*s);
	if (*s == NULL || **s == '\0')
		return ;
	if (len > 0 && (*s)[len - 1] == '\n')
	{
		(*s)[len - 1] = '\0';
	}
}
