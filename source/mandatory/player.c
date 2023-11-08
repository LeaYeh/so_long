/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:22:33 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/07 21:23:18 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_player(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			if (game->map->grid[row][col] == 'P')
			{
				draw_block(game, game->s_player[0], row * BLOC_PX, col * BLOC_PX);
				break;
			}
			col++;
		}
		row++;
	}
}

void	process_player(t_game *game)
{
	draw_player(game);
}
