/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:45:18 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/05 17:00:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool	remove_last_newline(char **s)
{
	int	len;

	if (*s == NULL || **s == '\0')
		return (false);
	len = ft_strlen(*s);
	if (len > 0 && (*s)[len - 1] == '\n')
		(*s)[len - 1] = '\0';
	return (true);
}
