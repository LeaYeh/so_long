/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:01:13 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:42:36 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	detect_obstacle(t_map *map, t_pos pos)
{
	if (map->grid[pos.row][pos.col] == '1')
		return (true);
	return (false);
}

bool	move(t_game *game, char item, int offset_row, int offset_col)
{
	if (item != 'P' && item != 'M')
		return (false);
	if (item == 'P')
		assign_pos(&(game->player.next_pos), \
			game->player.cur_pos.row + offset_row, \
			game->player.cur_pos.col + offset_col);
	return (true);
}

bool	change_direction(t_game *game, char item, int direction)
{
	if (item != 'P' && item != 'M')
		return (false);
	if (item == 'P')
		game->player.direction = direction;
	return (true);
}
