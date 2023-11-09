/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/09 16:59:11 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;

	if (init_game(&game))
	{
		if (!init_map(&game, argc, argv) || \
			!init_sprites(&game) || !init_player(&game))
			return (free_game(&game), -1);
		register_event(&game);
		init_process(&game);
		mlx_loop(game.mlx);
		mlx_destroy_window(game.mlx, game.window);
		free_game(&game);
	}
}
