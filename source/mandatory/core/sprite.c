/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:01:50 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/21 14:39:34 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_sprite_path(char *category, int n)
{
	char	*path;

	ft_sprintf(&path, "%s/%s/%d.xpm", TEXTURES_FOLDER, category, n);
	return (path);
}

void	*file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
{
	return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}

bool	load_sprite_category(
	t_game *game, char *category, char *file_path, int i)
{
	int		size;
	void	*tmp_img;

	size = BLOC_PX;
	tmp_img = file_to_image(game->mlx, file_path, &size, &size);
	if (!tmp_img)
		return (false);
	if (ft_strcmp(category, "background") == 0)
		game->s_background[i] = tmp_img;
	else if (ft_strcmp(category, "wall") == 0)
		game->s_wall[i] = tmp_img;
	else if (ft_strcmp(category, "player") == 0)
		game->s_player[i] = tmp_img;
	else if (ft_strcmp(category, "collect") == 0)
		game->s_collect[i] = tmp_img;
	else if (ft_strcmp(category, "exit") == 0)
		game->s_exit[i] = tmp_img;
	return (true);
}

bool	load_sprite(t_game *game, char *category, int num)
{
	int		i;
	char	*path;
	int		fd;

	i = 0;
	while (i < num)
	{
		path = get_sprite_path(category, i);
		fd = open(path, O_RDONLY);
		close(fd);
		if (fd < 0)
		{
			ft_dprintf(2, "Error\nInvalid texture path: %s\n", path);
			return (free(path),
				free_sprite(game, get_sprite_by_category(game, category), i),
				false);
		}
		if (!load_sprite_category(game, category, path, i))
			return (free(path),
				free_sprite(game, get_sprite_by_category(game, category), i),
				false);
		free(path);
		i++;
	}
	return (true);
}

bool	init_sprites(t_game *game)
{
	if (!load_sprite(game, "background", 1))
		return (false);
	if (!load_sprite(game, "wall", 1))
		return (free_sprite(game, game->s_background, 1), false);
	if (!load_sprite(game, "exit", 1))
		return (free_sprite(game, game->s_background, 1),
			free_sprite(game, game->s_wall, 1),
			false);
	if (!load_sprite(game, "player", 2))
		return (free_sprite(game, game->s_background, 1),
			free_sprite(game, game->s_wall, 1),
			free_sprite(game, game->s_exit, 1),
			false);
	if (!load_sprite(game, "collect", 6))
		return (free_sprite(game, game->s_background, 1),
			free_sprite(game, game->s_wall, 1),
			free_sprite(game, game->s_exit, 1),
			free_sprite(game, game->s_player, 2),
			false);
	return (true);
}
