/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:32:34 by lyeh             ###   ########.fr       */
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
		// if (!init_sprites(&game) || !init_player(&game) || !init_camera(&game))
		if (!init_sprites(&game))
		{
			ft_dprintf(2, "Error\n");
			free_map(game.map);
			free_mlx(&game);
			return (-1);
		}
		if (!init_player(&game))
			return (free_game(&game), -1);
		if (!init_camera(&game))
			return (free_game(&game), -1);
		register_event(&game);
		init_process(&game);
		mlx_loop(game.mlx);
	}
	else
		ft_dprintf(2, "Error\n");
}
