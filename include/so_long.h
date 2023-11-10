/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyeh <lyeh@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:33:58 by lyeh              #+#    #+#             */
/*   Updated: 2023/11/10 16:34:35 by lyeh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* open, close */
# include <fcntl.h>
/* malloc, free */
# include <stdlib.h>
/* perror, strerror */
# include <stdio.h>
# include <stdbool.h>
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

# ifdef __LINUX__
#  define OS "linux"
#  define LETTER_KEY_LEFT		97
#  define LETTER_KEY_RIGHT		100
#  define LETTER_KEY_UP       	119
#  define LETTER_KEY_DOWN		115
#  define LETTER_KEY_ACTION		101
#  define ARROW_KEY_LEFT	 	65361
#  define ARROW_KEY_RIGHT		65363
#  define ARROW_KEY_UP			65362
#  define ARROW_KEY_DOWN		65364
#  define SPACE_BAR				32
#  define KEY_ESC				65307
# elif __APPLE__
#  define OS "macos"
#  define LETTER_KEY_LEFT       0
#  define LETTER_KEY_RIGHT      2
#  define LETTER_KEY_UP 		13
#  define LETTER_KEY_DOWN		1
#  define LETTER_KEY_ACTION		14
#  define ARROW_KEY_LEFT		123
#  define ARROW_KEY_RIGHT		124
#  define ARROW_KEY_UP			126
#  define ARROW_KEY_DOWN		125
#  define SPACE_BAR				49
#  define KEY_ESC				53
# endif

# define WINDOW_TITLE "so_long"
# define WINDOW_WIDTH 1300
# define WINDOW_HEIGHT 700
# define TEXTURES_FOLDER "assets/textures"
# define BLOC_PX 100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// # define WINDOW_HEIGHT 768

typedef struct s_pos {
	int	row;
	int	col;
}	t_pos;

typedef struct s_map {
	char	**grid;
	char	*file_path;
	int		fd;
	int		width;
	int		height;
	int		player_cnt;
	int		monster_cnt;
	int		collect_cnt;
	int		exit_cnt;
}	t_map;

typedef struct s_player {
	t_pos	cur_pos;
	t_pos	next_pos;
	t_pos	top_left;
	t_pos	top_right;
	t_pos	bottom_left;
	t_pos	bottom_right;
	int		direction;
	int		move_cnt;
}	t_player;

typedef struct s_game {
	void		*mlx;
	void		*window;
	int			win_bloc_width;
	int			win_bloc_height;
	t_map		*map;
	t_player	player;
	void		*s_player[2];
	void		*s_collect[6];
	void		*s_background;
	void		*s_wall;
	void		*s_exit;
	t_pos		window_offset;
	int			collect_cnt;
}	t_game;

/* Game */
bool	init_game(t_game *game);
bool	init_camera(t_game *game);
void	init_process(t_game *game);
void	game_process(t_game *game);
bool	offset_camera_by_player(t_game *game);
/* Map */
bool	init_map(t_game *game, int argc, char **argv);
bool	check_map_input(t_map *map);
bool	check_object_count(t_map *map);
bool	check_wall_surround(t_map *map);
bool	check_workable(t_map *map);
/* Position */
t_pos	*get_item_pos(t_map *map, char item);
void	assign_pos(t_pos *dest, int row, int col);
/* Sprite */
bool	init_sprites(t_game *game);
/* Draw */
void	draw_block(t_game *game, void *sprite, int x, int y);
void	draw_background(t_game *game);
void	draw_wall(t_game *game);
void	draw_collect(t_game *game);
void	draw_player(t_game *game);
/* Background */
void	process_background(t_game *game);
/* Player */
bool	init_player(t_game *game);
void	process_player(t_game *game);
/* Wall */
void	process_wall(t_game *game);
/* Collect */
void	process_collect(t_game *game);
/* Exit */
void	process_exit(t_game *game);
/* Event */
void	register_event(t_game *game);
int		close_game(t_game *game);
/* Action */
bool	move(t_game *game, char item, int offset_row, int offset_col);
bool	detect_obstacle(t_map *map, t_pos pos);
bool	change_direction(t_game *game, char item, int direction);
/* Utils */
int		get_array_len(void **arr);
char	**copy_2darray(char **arr, int height);
/* Free */
void	free_game(t_game *game);
void	free_map(t_map *map);
void	free_2darray(char **arr, int idx);
/* Debug */
void	print_2darray(char **content, int height, int width);

#endif