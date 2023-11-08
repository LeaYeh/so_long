/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:24:57 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/07 21:43:32 by lyeh             ###   ########.fr       */
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

void	process_exit(t_game *game)
{
    printf("game->collect_cnt = %d\n", game->collect_cnt);
    printf("game->map->collect_cnt = %d\n", game->map->collect_cnt);
    if (game->collect_cnt == game->map->collect_cnt)
	    draw_exit(game);
}
