/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 19:33:39 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_game(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	on_keybord(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		close_game(game);
	return (0);
}

void	register_event(t_game *game)
{
	mlx_hook(game->window, DestroyNotify, KeyReleaseMask, close_game, game);
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, on_keybord, game);
}
