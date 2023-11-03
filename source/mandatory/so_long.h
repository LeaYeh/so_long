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
# define BUFFER_SIZE 128

// # define WINDOW_HEIGHT 768

typedef struct s_game {
	void	*mlx;
	void	*window;
	char	**map;
	int		map_fd;
	int		map_width;
	int		map_height;
}	t_game;

void	init_game(t_game *game);
bool	init_map(t_game *game, int argc, char **argv);

#endif