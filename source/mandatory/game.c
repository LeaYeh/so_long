/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:13:29 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/09 16:58:17 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->window = mlx_new_window(
			game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game->window)
		return (false);
	game->map = NULL;
	game->collect_cnt = 0;
	return (true);
}

void	init_process(t_game *game)
{
	process_background(game);
	process_wall(game);
	process_collect(game);
	process_exit(game);
	process_player(game);
}

void	game_process(t_game *game)
{
	process_collect(game);
	process_exit(game);
	process_player(game);
}
