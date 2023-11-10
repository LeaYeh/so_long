/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:55:05 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 20:46:23 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	limit_args(t_map **map, int argc, char **argv)
{
	if (argc != 2)
	{
		ft_dprintf(2, "Error\nNeed 1 argument.\n");
		return (false);
	}
	(*map)->file_path = ft_strdup(argv[1]);
	if (!(*map)->file_path)
		return (false);
	return (true);
}

bool	open_map_file(t_map **map)
{
	const int	len = ft_strlen((*map)->file_path);

	if (len < 5)
	{
		ft_dprintf(2, "Error\nInvalid map file name.\n");
		return (false);
	}
	if (ft_strncmp(((*map)->file_path + len - 4), ".ber", 4) != 0)
	{
		ft_dprintf(2, "Error\nInvalid map file extension.\n");
		return (false);
	}
	(*map)->fd = open((*map)->file_path, O_RDONLY);
	if ((*map)->fd == -1)
	{
		ft_dprintf(2, "Error\nFailed to read map file %s\n", (*map)->file_path);
		return (false);
	}
	return (true);
}

bool	parse_map_size(t_map **map)
{
	char	*buf;
	int		read_bytes;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (false);
	read_bytes = -1;
	while (read_bytes)
	{
		read_bytes = read((*map)->fd, buf, BUFFER_SIZE);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 0)
			return (free(buf), false);
		while (read_bytes-- > 0)
		{
			if (buf[read_bytes] == '\n')
				(*map)->height++;
			else if ((*map)->height == 1 && buf[read_bytes] != '\n')
				(*map)->width++;
		}
	}
	free(buf);
	close((*map)->fd);
	return (true);
}

bool	load_map(t_map **map)
{
	char	*line;
	int		i;

	i = 0;
	(*map)->grid = (char **)malloc(sizeof(char *) * ((*map)->height + 1));
	while (i < (*map)->height)
	{
		line = get_next_line((*map)->fd);
		if (!remove_last_newline(&line))
			return (free_2darray((*map)->grid, i), free(line), false);
		if ((int)ft_strlen(line) != (*map)->width)
		{
			ft_dprintf(2, "Error\nInvalid shape of map\n");
			close((*map)->fd);
			get_next_line((*map)->fd);
			return (free_2darray((*map)->grid, i), free(line), false);
		}
		(*map)->grid[i] = ft_strdup(line);
		if (!(*map)->grid[i])
			return (free_2darray((*map)->grid, i), free(line), false);
		free(line);
		i++;
	}
	(*map)->grid[(*map)->height] = NULL;
	return (true);
}

bool	init_map(t_game *game, int argc, char **argv)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		return (false);
	game->map->file_path = NULL;
	game->map->fd = -1;
	game->map->height = 1;
	game->map->width = 0;
	game->map->player_cnt = 0;
	game->map->monster_cnt = 0;
	game->map->collect_cnt = 0;
	game->map->exit_cnt = 0;
	if (!limit_args(&(game->map), argc, argv))
		return (free(game->map), false);
	if (!open_map_file(&(game->map)) || !parse_map_size(&(game->map)))
		return (free(game->map->file_path), free(game->map), false);
	if (!open_map_file(&(game->map)) || !load_map(&(game->map)))
		return (free(game->map->file_path), free(game->map), false);
	if (game->map->width < 3 || game->map->height < 3)
		return (free_map(game->map),
			ft_dprintf(2, "Error\nInvalid size of map.\n"), false);
	if (!check_map_input(game->map) || !check_object_count(game->map) || \
		!check_wall_surround(game->map))
		return (free_map(game->map), false);
	if (!check_workable(game->map))
		return (free_map(game->map),
			ft_dprintf(2, "Error\nThe map is not workable.\n"), false);
	return (true);
}
