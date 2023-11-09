/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:20:20 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/09 17:27:44 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	free_game(game);
	exit(EXIT_SUCCESS);
}

int	on_keybord(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		close_game(game);
	else if (key_code == ARROW_KEY_UP || key_code == LETTER_KEY_UP)
		move(game, 'P', -1, 0);
	else if (key_code == ARROW_KEY_DOWN || key_code == LETTER_KEY_DOWN)
		move(game, 'P', 1, 0);
	else if (key_code == ARROW_KEY_LEFT || key_code == LETTER_KEY_LEFT)
	{
		move(game, 'P', 0, -1);
		change_direction(game, 'P', 1);
	}
	else if (key_code == ARROW_KEY_RIGHT || key_code == LETTER_KEY_RIGHT)
	{
		move(game, 'P', 0, 1);
		change_direction(game, 'P', 0);
	}
	game_process(game);
	return (0);
}

void	register_event(t_game *game)
{
	mlx_hook(game->window, KeyRelease, KeyReleaseMask, on_keybord, game);
}
