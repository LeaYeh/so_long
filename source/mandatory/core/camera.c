/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:50:51 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:59:29 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	_offset_row(t_game *game)
{
	if (game->map->height >= game->win_bloc_height)
	{
		game->window_offset.row = \
			(game->player.cur_pos.row - game->win_bloc_height / 2);
		if (game->window_offset.row < 0)
		{
			game->window_offset.row = 0;
			return (true);
		}
		else if (
			game->window_offset.row + game->win_bloc_height > game->map->height)
		{
			game->window_offset.row = game->map->height - game->win_bloc_height;
			return (true);
		}
		game->window_offset.row *= -1 * BLOC_PX;
	}
	return (false);
}

bool	_offset_col(t_game *game)
{
	if (game->map->width >= game->win_bloc_width)
	{
		game->window_offset.col = \
			(game->player.cur_pos.col - game->win_bloc_width / 2);
		if (game->window_offset.col < 0)
		{
			game->window_offset.col = 0;
			return (true);
		}
		else if (
			game->window_offset.col + game->win_bloc_width > game->map->width)
		{
			game->window_offset.col = game->map->width - game->win_bloc_width;
			return (true);
		}
		game->window_offset.col *= -1 * BLOC_PX;
	}
	return (false);
}

bool	offset_camera_by_player(t_game *game)
{
	bool	ret;

	ret = false;
	ret |= _offset_row(game);
	ret |= _offset_col(game);
	return (ret);
}

bool	init_camera(t_game *game)
{
	if (game->map->height <= 0 || game->map->width <= 0)
		return (false);
	assign_pos(&(game->window_offset), 0, 0);
	if (game->map->width < game->win_bloc_width)
		game->window_offset.col = \
			(game->win_bloc_width - game->map->width) / 2 * BLOC_PX;
	if (game->map->height < game->win_bloc_height)
		game->window_offset.row = \
			(game->win_bloc_height - game->map->height) / 2 * BLOC_PX;
	offset_camera_by_player(game);
	return (true);
}
