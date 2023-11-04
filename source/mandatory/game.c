/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:13:29 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/04 17:39:06 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_game(t_game *game)
{
	free(game->mlx);
	free(game->window);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(
			game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	// game->map = (t_map *)malloc(sizeof(t_map));
	game->map = NULL;
	game->map_path = NULL;
	game->map_fd = -1;
	game->map_height = 1;
	game->map_width = 0;
	game->player_cnt = 0;
	game->monster_cnt = 0;
	game->collect_cnt = 0;
	game->exit_cnt = 0;
}
