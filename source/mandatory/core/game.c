/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:13:29 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 18:43:48 by lyeh             ###   ########.fr       */
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
	game->win_bloc_width = WINDOW_WIDTH / BLOC_PX;
	game->win_bloc_height = WINDOW_HEIGHT / BLOC_PX;
	return (true);
}

void	init_process(t_game *game)
{
	render_items(game);
	process_exit(game);
}

void	game_process(t_game *game)
{
	process_player(game);
	process_collect(game);
	render_items(game);
	process_exit(game);
}
