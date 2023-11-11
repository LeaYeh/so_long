/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:40:38 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 20:22:45 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_2darray(char **arr, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
		free(arr[i++]);
	free(arr);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free_2darray(map->grid, map->height);
	free(map->file_path);
	free(map);
}

void	free_sprite(t_game *game, void **sprite, int num)
{
	int	i;

	if (num == 1)
		mlx_destroy_image(game->mlx, *sprite);
	else
	{
		i = 0;
		while (i < num)
			mlx_destroy_image(game->mlx, sprite[i++]);
	}
}

void	free_mlx(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	game->window = NULL;
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_game(t_game *game)
{
	free_sprite(game, game->s_collect, 6);
	free_sprite(game, game->s_player, 2);
	free_sprite(game, game->s_background, 1);
	free_sprite(game, game->s_wall, 1);
	free_sprite(game, game->s_exit, 1);
	free_mlx(game);
	free_map(game->map);
}
