/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 13:22:12 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 19:34:02 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_pos	*get_item_pos(t_map *map, char item)
{
	int		row;
	int		col;
	t_pos	*pos;

	pos = (t_pos *)malloc(sizeof(t_pos));
	if (!pos)
		return (NULL);
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			if (map->grid[row][col] == item)
			{
				pos->row = row;
				pos->col = col;
				return (pos);
			}
			col++;
		}
		row++;
	}
	return (NULL);
}

void	assign_pos(t_pos *dest, int row, int col)
{
	dest->row = row;
	dest->col = col;
}
