/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:55:05 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/04 00:06:38 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	limit_args(t_game *game, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_dprintf(2, "Need 1 argument.\n");
		return (false);
	}
	game->map_path = argv[1];
	return (true);
}

bool	open_map_file(t_game *game)
{
	const int	len = ft_strlen(game->map_path);
	
	if (len < 5)
	{
		ft_dprintf(2, "Invalid map file name.\n");
		return (false);
	}
	if (ft_strncmp((game->map_path + len - 4), ".ber", 4) != 0)
	{
		ft_dprintf(2, "Invalid map file extension.\n");
		return (false);
	}
	game->map_fd = open(game->map_path, O_RDONLY);
	if (game->map_fd == -1)
	{
		ft_dprintf(2, "Failed to read map file %s\n", game->map_path);
		return (false);
	}
	return (true);
}

bool	parse_map_size(t_game *game)
{
	char	*buf;
	int	read_bytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (false);
	read_bytes = -1;
	while (read_bytes)
	{
		read_bytes = read(game->map_fd, buf, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 0)
			return (free(buf), false);
		while (read_bytes-- > 0)
		{
			if (buf[read_bytes] == '\n')
				game->map_height++;
			else if (game->map_height == 1 && buf[read_bytes] != '\n')
				game->map_width++;
		}
	}
	free(buf);
	close(game->map_fd);
	return (true);
}

void	free_map(t_game *game, int idx)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

bool	load_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_height + 1));
	while (i < game->map_height)
	{
		line = get_next_line(game->map_fd);
		remove_last_newline(&line);
		if ((int)ft_strlen(line) != game->map_width)
		{
			ft_dprintf(2, 
				"Invalid shape of map (w: %d and h: %d, but got %d)\n",
				game->map_width, game->map_height, ft_strlen(line));
			return (free_map(game, i), free(line), false);
		}
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
			return (free_map(game, i), free(line), false);
		free(line);
		i++;
	}
	game->map[game->map_height] = NULL;
	return (true);
}

bool	init_map(t_game *game, int argc, char **argv)
{
	if (!limit_args(game, argc, argv))
		return (false);
	if (!open_map_file(game) || !parse_map_size(game))
		return (false);
	if (!open_map_file(game) || !load_map(game))
		return (false);
	close(game->map_fd);
	exit(1);
	return (true);
}
