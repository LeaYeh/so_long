/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:42:05 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 13:57:28 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_flooding(const t_map *map, char **check_map, int row, int col)
{
	if ((row < 0 || row >= map->height) || (col < 0 || col >= map->width))
		return ;
	if (check_map[row][col] == '1' || check_map[row][col] == '*')
		return ;
	else
		check_map[row][col] = '*';
	_flooding(map, check_map, row - 1, col);
	_flooding(map, check_map, row + 1, col);
	_flooding(map, check_map, row, col - 1);
	_flooding(map, check_map, row, col + 1);
}

bool	check_workable(t_map *map)
{
	int		row;
	int		col;
	char	**check_map;
	t_pos	*start_pos;

	check_map = copy_2darray(map->grid, map->height);
	if (!check_map)
		return (false);
	start_pos = get_item_pos(map, 'P');
	if (!start_pos)
		return (free_2darray(check_map, map->height), false);
	_flooding(map, check_map, start_pos->row, start_pos->col);
	row = 0;
	while (row < map->height)
	{
		col = -1;
		while (col++ < map->width)
		{
			if (check_map[row][col] == 'C' || check_map[row][col] == 'E')
				return (free(start_pos),
					free_2darray(check_map, map->height), false);
		}
		row++;
	}
	return (free(start_pos), free_2darray(check_map, map->height), true);
}

bool	check_wall_surround(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if ((row == 0 || row == map->height - 1) || \
				(col == 0 || col == map->width - 1))
			{
				if (map->grid[row][col] != '1')
					return (
						ft_dprintf(2,
							"Error\nWall is not surround the map (%d, %d)\n",
							row, col),
						false);
			}
			col++;
		}
		row++;
	}
	return (true);
}

bool	check_object_count(t_map *map)
{
	if (map->player_cnt != 1)
		return (
			ft_dprintf(2, "Player count: %d != 1\n", map->player_cnt), false);
	if (map->collect_cnt < 1)
		return (ft_dprintf(2, "Collection count: %d < 1\n",
				map->collect_cnt), false);
	if (map->exit_cnt != 1)
		return (
			ft_dprintf(2, "Exit count: %d < 1\n", map->exit_cnt), false);
	return (true);
}

bool	check_map_input(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->grid[row][col] == 'P')
				map->player_cnt++;
			else if (map->grid[row][col] == 'C')
				map->collect_cnt++;
			else if (map->grid[row][col] == 'E')
				map->exit_cnt++;
			else if (map->grid[row][col] == 'M')
				map->monster_cnt++;
			else if (map->grid[row][col] != '0' && map->grid[row][col] != '1')
				return (ft_dprintf(2, "Invalid conent of '%c'\n",
						map->grid[row][col]), false);
			col++;
		}
		row++;
	}
	return (true);
}
