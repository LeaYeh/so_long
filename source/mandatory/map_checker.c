/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:42:05 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/04 17:39:37 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void water_flooding(t_game *game, char **check_map, int row, int col)
// {
// 	if (map[])
// }

// bool	check_workable(t_game *game)
// {
	
// }

bool    check_wall_surround(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			if ((row == 0 || row == game->map_height - 1) || \
				(col == 0 || col == game->map_width - 1))
			{
				if (game->map[row][col] != '1')
					return (false);
			}
			col++;
		}
		row++;
	}
	return (true);
}

bool    check_object_count(t_game *game)
{
	if (game->player_cnt != 1)
		return (false);
	if (game->collect_cnt < 1)
		return (false);
	if (game->exit_cnt != 1)
		return (false);
	return (true);
}

bool	check_map_input(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->map_height)
	{
		col = 0;
		while (col < game->map_width)
		{
			if (game->map[row][col] == 'P')
				game->player_cnt++;
			else if (game->map[row][col] == 'C')
				game->collect_cnt++;
			else if (game->map[row][col] == 'E')
				game->exit_cnt++;
			else if (game->map[row][col] == 'M')
				game->monster_cnt++;
			else if (game->map[row][col] != '0' && game->map[row][col] != '1')
				return (false);
			col++;
		}
		row++;
	}
	return (true);
}
