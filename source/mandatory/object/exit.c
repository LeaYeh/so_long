/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:24:57 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:35:49 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_exit(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map->height)
	{
		col = 0;
		while (col < game->map->width)
		{
			if (game->map->grid[row][col] == 'E')
				draw_block(game, game->s_exit, row * BLOC_PX, col * BLOC_PX);
			col++;
		}
		row++;
	}
}

void	interact_exit(t_game *game)
{
	t_pos	pos;

	pos = game->player.cur_pos;
	if (game->collect_cnt == game->map->collect_cnt && \
		game->map->grid[pos.row][pos.col] == 'E')
	{
		ft_dprintf(1, "YOU WIN!\n");
		close_game(game);
	}
}

void	process_exit(t_game *game)
{
	if (game->collect_cnt == game->map->collect_cnt)
		draw_exit(game);
	interact_exit(game);
}
