/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:22:33 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 14:23:05 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	init_player(t_game *game)
{
	t_pos	*pos;

	if (!game->map)
		return (false);
	pos = get_item_pos(game->map, 'P');
	if (!pos)
		return (false);
	assign_pos(&(game->player.cur_pos), pos->row, pos->col);
	assign_pos(&(game->player.cur_pos), pos->row, pos->col);
	assign_pos(&(game->player.top_left), pos->row, pos->col);
	assign_pos(&(game->player.top_right), pos->row, pos->col + BLOC_PX);
	assign_pos(&(game->player.bottom_left), pos->row + BLOC_PX, pos->col);
	assign_pos(&(game->player.bottom_right), \
		pos->row + BLOC_PX, pos->col + BLOC_PX);
	game->player.direction = 0;
	game->player.move_cnt = 0;
	free(pos);
	return (true);
}

void	draw_player(t_game *game)
{
	draw_block(game, game->s_player[game->player.direction],
		game->player.cur_pos.row * BLOC_PX,
		game->player.cur_pos.col * BLOC_PX);
}

void	move_player(t_game *game)
{
	if (detect_obstacle(game->map, game->player.next_pos))
		return ;
	assign_pos(&(game->player.cur_pos),
		game->player.next_pos.row, game->player.next_pos.col);
	game->player.move_cnt++;
	ft_dprintf(1, "Total move count: %d\n", game->player.move_cnt);
}

void	process_player(t_game *game)
{
	move_player(game);
	offset_camera_by_player(game);
}
