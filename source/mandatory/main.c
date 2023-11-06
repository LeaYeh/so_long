/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:01:47 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/05 20:06:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	t_game	game;
	void	*img;

	if (init_game(&game))
	{
		if (!init_map(&game, argc, argv))
			return (free_game(&game), -1);
	}
	// img = mlx_xpm_file_to_image(
	// 	game.mlx, "../../assets/textures/background/bg_0.xpm", &(game.map->height), &(game.map->width));
	// mlx_put_image_to_window(game.mlx, game.window, img, 0, 0);
}
