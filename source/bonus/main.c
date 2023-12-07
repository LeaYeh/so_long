/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:18:23 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 22:17:23 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	game_loop(t_game *game)
{
	long long	now;

	now = ms_timestamp();
	if ((now - game->last_ms) > 10)
	{
		mlx_clear_window(game->mlx, game->window);
		set_fps(game);
		show_fps(game);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_map(&game, argc, argv))
	{
		if (!init_game(&game))
			return (free_map(game.map), -1);
		// if (!init_sprites(&game))
		// 	return (free_map(game.map), free_mlx(&game), -1);
		register_event(&game);
		// mlx_string_put(game.mlx, game.window, 20, 30, 11001101, "haha");
		mlx_loop_hook(game.mlx, game_loop, &game);
		mlx_loop(game.mlx);
	}
}
