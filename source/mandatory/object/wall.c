/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:22:18 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/21 14:24:41 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_wall(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			if (game->map->grid[row][col] == '1')
				draw_block(game, game->s_wall[0], row * BLOC_PX, col * BLOC_PX);
			col++;
		}
		row++;
	}
}
