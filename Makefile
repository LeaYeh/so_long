END				= $'\x1b[0m
BOLD			= $'\x1b[1m
UNDER			= $'\x1b[4m
REV				= $'\x1b[7m
GREY			= $'\x1b[30m
RED				= $'\x1b[31m
GREEN			= $'\x1b[32m
YELLOW			= $'\x1b[33m
BLUE			= $'\x1b[34m
PURPLE			= $'\x1b[35m
CYAN			= $'\x1b[36m
WHITE			= $'\x1b[37m

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
	INCLUDES 		+= -I/usr/include -I$(MLX_DIR)
	MLX_LIB			= mlx
	MLX_LIB_PATH	= $(MLX_DIR)/libmlx.a
	MLX_FLAGS 		= -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES 		+= -I/opt/X11/include -I$(MLX_DIR)
	MLX_LIB_PATH	= $(MLX_DIR)/libmlx.dylib
	MLX_FLAGS 		= -L$(MLX_DIR) -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit -l z
endif

CC			= cc
RM			= rm -f
# CFLAGS		= -Wall -Wextra -Werror -g
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

.PHONY:		all bonus clean fclean re

all: 		$(NAME)

$(NAME): 	premake $(OBJS)
			$(CC) $(CFLAGS) $(MLX_LIB_PATH) $(AR_FILES) $(OBJS) $(MLX_FLAGS) -o $(NAME)
			@echo "$(GREEN)> All success! $(END)"


premake:
			@make -C $(LIB_DIR)
			@echo "$(GREEN)> Pre-make success! $(END)"

clean:
			@make -C $(LIB_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			@make -C $(LIB_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all
