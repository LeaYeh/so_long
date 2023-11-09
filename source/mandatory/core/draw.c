/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:58:12 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/07 19:19:09 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_block(t_game *game, void *sprite, int row, int col)
{
	if (row < -BLOC_PX || col < -BLOC_PX || \
		row > WINDOW_HEIGHT || col > WINDOW_WIDTH)
		return ;
	mlx_put_image_to_window(game->mlx, game->window, sprite, col, row);
}
