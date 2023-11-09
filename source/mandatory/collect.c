/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:45:21 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/09 17:50:25 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_collect(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			if (game->map->grid[row][col] == 'C')
				draw_block(game, game->s_collect[0], row * BLOC_PX, col * BLOC_PX);
			col++;
		}
		row++;
	}
}

void	interact_collect(t_game *game)
{
	t_pos	pos;

	pos = game->player.cur_pos;
	if (game->map->grid[pos.row][pos.col] == 'C')
	{
		game->map->grid[pos.row][pos.col] = '0';
		game->collect_cnt++;
	}
}

void	process_collect(t_game *game)
{
	interact_collect(game);
}
