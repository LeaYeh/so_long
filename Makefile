NAME			:= so_long
SRC_DIR			:= source/mandatory
BUILD_DIR		:= build
INCL_DIR		:= include
LIB_DIR			:= library
MLX_DIR			:= $(LIB_DIR)/mlx
AR_FILES		:= $(LIB_DIR)/build/libft.a \
				$(LIB_DIR)/build/libftprintf.a \
				$(LIB_DIR)/build/libgnl.a

SRCS		:= core/main.c \
			core/game.c \
			core/action.c \
			core/sprite.c \
			core/draw.c \
			core/event.c \
			core/free.c \
			core/position.c \
			map/map.c \
			map/map_checker.c \
			object/background.c \
			object/player.c \
			object/wall.c \
			object/collect.c \
			object/exit.c \
			tool/utils.c \
			tool/debug.c
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 		:= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

INCLUDES	:= -I$(LIB_DIR)/build -I$(INCL_DIR)

UNAME		:= $(shell uname)
ifeq ($(UNAME), Linux)
	INCLUDES += -I/usr/include -I$(MLX_DIR)
	MLX_LIB	= mlx
	MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES += -I/opt/X11/include -I$(MLX_DIR)
	MLX_LIB	= mlx_$(UNAME)
	MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

CC			= cc
RM			= rm -f
# CFLAGS		= -Wall -Wextra -Werror -g
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

.PHONY:		all bonus clean fclean re

all: 		$(NAME)

$(NAME): 	premake $(OBJS)
			$(CC) $(CFLAGS) $(LIB_DIR)/build/libftprintf.a $(LIB_DIR)/build/libgnl.a $(OBJS) -o $(NAME) $(MLX_FLAGS)

premake:
			@make -C $(LIB_DIR)

clean:
			@make -C $(LIB_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			@make -C $(LIB_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all
