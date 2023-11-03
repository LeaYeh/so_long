/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:55:05 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/03 22:22:34 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	limit_args(int argc)
{
	if (argc != 2)
	{
		ft_dprintf(2, "Need 1 argument.\n");
		return (false);
	}
	return (true);
}

bool	open_map_file(t_game *game, char *path)
{
	const int	len = ft_strlen(path);
	
	if (len < 5)
	{
		ft_dprintf(2, "Invalid map file name.\n");
		return (false);
	}
	if (ft_strncmp((path + len - 4), ".ber", 4) != 0)
	{
		ft_dprintf(2, "Invalid map file extension.\n");
		return (false);
	}
	game->map_fd = open(path, O_RDONLY);
	if (game->map_fd == -1)
	{
		ft_dprintf(2, "Failed to read map file %s\n", path);
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
	return (true);
}

bool	init_map(t_game *game, int argc, char **argv)
{
	if (!limit_args(argc))
		return (false);
	if (!open_map_file(game, argv[1]))
		return (false);
	if (!parse_map_size(game))
		return (false);
	ft_dprintf(1, "width: %d, height: %d\n", game->map_width, game->map_height);
	close(game->map_fd);
	exit(1);
	return (true);
}
