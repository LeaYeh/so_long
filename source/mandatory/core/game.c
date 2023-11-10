/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:13:29 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:28:51 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	offset_camera_by_player(t_game *game)
{
	bool	ret;

	ret = false;
	if (game->map->width >= game->win_bloc_width)
	{
		game->window_offset.col = (game->player.cur_pos.col - game->win_bloc_width / 2);
		if (game->window_offset.col < 0)
			game->window_offset.col = 0;
		else if (game->window_offset.col + game->win_bloc_width > game->map->width)
			game->window_offset.col = game->map->width - game->win_bloc_width;
		game->window_offset.col *= -1 * BLOC_PX;
		ret = true;
	}
	if (game->map->height > game->win_bloc_height)
	{
		game->window_offset.row = (game->player.cur_pos.row - game->win_bloc_height / 2);
		if (game->window_offset.row < 0)
			game->window_offset.row = 0;
		else if (game->window_offset.row + game->win_bloc_height > game->map->height)
			game->window_offset.row = game->map->height - game->win_bloc_height;
		game->window_offset.row *= -1 * BLOC_PX;
		ret = true;
	}
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

bool	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	game->window = mlx_new_window(
			game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
	if (!game->window)
		return (false);
	game->map = NULL;
	game->collect_cnt = 0;
	game->win_bloc_width = WINDOW_WIDTH / BLOC_PX;
	game->win_bloc_height = WINDOW_HEIGHT / BLOC_PX;
	return (true);
}

void	init_process(t_game *game)
{
	draw_background(game);
	draw_wall(game);
	draw_collect(game);
	process_exit(game);
	draw_player(game);
}

void	game_process(t_game *game)
{
	process_player(game);
	process_collect(game);
	process_exit(game);
	draw_collect(game);
	draw_player(game);
}
