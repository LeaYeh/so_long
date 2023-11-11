/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 18:27:25 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (init_map(&game, argc, argv))
	{
		if (!init_game(&game))
			return (free_map(game.map), -1);
		if (!init_sprites(&game))
			return (free_map(game.map), free_mlx(&game), -1);
		if (!init_player(&game))
			return (free_game(&game), -1);
		if (!init_camera(&game))
			return (free_game(&game), -1);
		register_event(&game);
		init_process(&game);
		mlx_loop(game.mlx);
	}
}
