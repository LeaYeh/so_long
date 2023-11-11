/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 19:35:11 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/11 22:17:03 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

long long	ms_timestamp(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_REALTIME, &ts);
	return ((ts.tv_sec) * 1000 + (ts.tv_nsec) / 1000000);
}

void	set_fps(t_game *game)
{
	long long	now;

	now = ms_timestamp();
	if (now > game->last_ms)
	{
		game->fps = 1000 / (now - game->last_ms);
		game->last_ms = now;
	}
}

void	show_fps(t_game *game)
{
	char	*tmp;

	ft_sprintf(&tmp, "%d", game->fps);
	mlx_string_put(game->mlx, game->window, 20, 30, 11001101, tmp);
	free(tmp);
}
