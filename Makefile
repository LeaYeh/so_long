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
SRC_DIR			:= source
MAJOR_DIR		:= $(SRC_DIR)/mandatory
BONUS_DIR		:= $(SRC_DIR)/bonus
BUILD_DIR		:= build
INCL_DIR		:= include
LIB_DIR			:= library
AR_FILES		:= $(LIB_DIR)/build/libft.a \
				$(LIB_DIR)/build/libftprintf.a \
				$(LIB_DIR)/build/libgnl.a

SRCS		:= core/main.c \
			core/game.c \
			core/action.c \
			core/camera.c \
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
SRCS		:= $(addprefix $(MAJOR_DIR)/, $(SRCS))
OBJS 		:= $(patsubst $(MAJOR_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

BONUS_SRCS	:= main.c \
			game.c \
			map.c \
			map_checker.c \
			draw.c \
			position.c \
			sprite.c \
			player.c \
			event.c \
			utils.c \
			fps.c \
			free.c
BONUS_SRCS	:= $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJS 	:= $(patsubst $(BONUS_DIR)/%.c, $(BUILD_DIR)/%.o, $(BONUS_SRCS))

INCLUDES	:= -I$(LIB_DIR)/build -I$(INCL_DIR)
MLX_FLAGS	:= -Lminilibx-linux -lmlx -lXext -lX11

CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -g
# CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address

$(BUILD_DIR)/%.o: $(MAJOR_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

.PHONY:		all bonus clean fclean re

$(NAME): 	$(AR_FILES) $(OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(AR_FILES) $(MLX_FLAGS) -o $(NAME)
			@echo "> $(GREEN)Mandatory: All success!$(END)"

$(AR_FILES):
			@make -s -C $(LIB_DIR)
			@echo "$(GREEN)> Pre-make success! $(END)"

all: 		$(NAME)

bonus:		$(AR_FILES) $(BONUS_OBJS)
			$(CC) $(CFLAGS) $(INCLUDES) $(BONUS_OBJS) $(AR_FILES) $(MLX_FLAGS) -o $(NAME)
			@echo "> $(GREEN)Bonus: All success!$(END)"

clean:
			@make -s -C $(LIB_DIR) clean
			@$(RM) -rf $(BUILD_DIR)

fclean:		clean
			@make -s -C $(LIB_DIR) fclean
			@$(RM) $(NAME)

re: 		fclean all
