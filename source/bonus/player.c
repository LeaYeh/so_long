/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:22:33 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 19:33:59 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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