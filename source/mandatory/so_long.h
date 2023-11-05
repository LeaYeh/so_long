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
# include "libft.h"
# include "ft_dprintf.h"
# include "get_next_line.h"

# ifdef __linux__
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
# define WINDOW_WIDTH 1366
# define WINDOW_HEIGHT 768
# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 128
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

typedef struct s_game {
	void	*mlx;
	void	*window;
	t_map	*map;
}	t_game;

bool	init_game(t_game *game);
bool	init_map(t_game *game, int argc, char **argv);

bool	check_map_input(t_map *map);
bool    check_object_count(t_map *map);
bool    check_wall_surround(t_map *map);
bool	check_workable(t_map *map);

t_pos	*get_player_pos(t_map *map);

int		get_array_len(void **arr);
char	**copy_2darray(char **arr, int height);

void	free_map(t_map *map);
void    free_2darray(char **arr, int idx);

void	print_2darray(char **content, int height, int width);

#endif