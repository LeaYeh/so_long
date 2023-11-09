/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/08 23:16:26 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_2darray(char **arr, int idx)
{
    int	i;

	i = 0;
	while (i < idx)
	{
		free(arr[i]);
		i++;
	}
    free(arr);
}

void	free_map(t_map *map)
{
	free_2darray(map->grid, map->height);
    free(map->file_path);
    free(map);
}

void	free_game(t_game *game)
{
	free_map(game->map);
}
