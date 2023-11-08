/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/08 22:17:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	// void	*img;

	if (init_game(&game))
	{
		if (!init_map(&game, argc, argv) || \
			!init_sprites(&game))
			return (free_game(&game), -1);
		process_background(&game);
		process_player(&game);
		process_wall(&game);
		process_collect(&game);
		process_exit(&game);
		mlx_loop(game.mlx);
	}
}
