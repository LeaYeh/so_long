/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:58:12 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 14:57:42 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_block(t_game *game, void *sprite, int row, int col)
{
	int	draw_row;
	int	draw_col;

	draw_row = row + game->window_offset.row;
	draw_col = col + game->window_offset.col;
	if (draw_row < -BLOC_PX || draw_col < -BLOC_PX || \
		draw_row > WINDOW_HEIGHT || draw_col > WINDOW_WIDTH)
		return ;
	mlx_put_image_to_window(
		game->mlx, game->window, sprite, draw_col, draw_row);
}
