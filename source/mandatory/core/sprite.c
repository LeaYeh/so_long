/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:01:50 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:36:41 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_sprite_path(char *category, int n)
{
	char	*path;

	if (ft_strcmp(OS, "macos"))
		ft_sprintf(&path, "%s/%s/%d.png", TEXTURES_FOLDER, category, n);
	else
		ft_sprintf(&path, "%s/%s/%d.xpm", TEXTURES_FOLDER, category, n);
	return (path);
}

void	*file_to_image(void *mlx_ptr, char *filename, int *width, int *height)
{
	if (ft_strcmp(OS, "macos"))
		return (mlx_png_file_to_image(mlx_ptr, filename, width, height));
	else
		return (mlx_xpm_file_to_image(mlx_ptr, filename, width, height));
}

void	load_sprite_category(
	t_game *game, char *category, char *file_path, int i)
{
	int		size;

	size = BLOC_PX;
	if (ft_strcmp(category, "background") == 0)
		game->s_background = \
			file_to_image(game->mlx, file_path, &size, &size);
	else if (ft_strcmp(category, "wall") == 0)
		game->s_wall = \
			file_to_image(game->mlx, file_path, &size, &size);
	else if (ft_strcmp(category, "player") == 0)
		game->s_player[i] = \
			file_to_image(game->mlx, file_path, &size, &size);
	else if (ft_strcmp(category, "collect") == 0)
		game->s_collect[i] = \
			file_to_image(game->mlx, file_path, &size, &size);
	else if (ft_strcmp(category, "exit") == 0)
		game->s_exit = \
			file_to_image(game->mlx, file_path, &size, &size);
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
			perror("");
			ft_dprintf(2, "Invalid texture path: %s\n", path);
			return (free(path), false);
		}
		load_sprite_category(game, category, path, i);
		free(path);
		i++;
	}
	return (true);
}

bool	init_sprites(t_game *game)
{
	if (!load_sprite(game, "background", 1) || \
		!load_sprite(game, "wall", 1) || \
		!load_sprite(game, "player", 2) || \
		!load_sprite(game, "collect", 6) || \
		!load_sprite(game, "exit", 1))
		return (false);
	return (true);
}
