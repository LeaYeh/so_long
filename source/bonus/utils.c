/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:12:02 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 19:34:14 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_array_len(void **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

char	**copy_2darray(char **arr, int height)
{
	char	**new_arr;
	int		i;

	new_arr = (char **)malloc(sizeof(char *) * (height + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < height)
	{
		new_arr[i] = ft_strdup(arr[i]);
		if (!new_arr[i])
			return (free_2darray(new_arr, i), NULL);
		i++;
	}
	new_arr[height] = NULL;
	return (new_arr);
}

void	terminate_gnl(int fd)
{
	close(fd);
	get_next_line(fd);
}
