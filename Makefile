NAME		:= so_long
SRC_DIR		:= source
BUILD_DIR	:= build
LIB_DIR		:= library
MLX_DIR		:= $(LIB_DIR)/mlx
LIBFT_DIR	:= $(LIB_DIR)/libft
DPRINTF_DIR	:= $(LIB_DIR)/ftdprintf

SRCS		:= so_long.c
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS 		:= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

INCLUDES	:= -Ilibrary/ftdprintf -Ilibrary/libft

UNAME		:= $(shell uname)
ifeq ($(UNAME), Linux)
	INCLUDES = -I/usr/include -I$(MLX_DIR)
	MLX_LIB	= mlx
	MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/lib/X11 -lXext -lX11
else
	INCLUDES = -I/opt/X11/include -I$(MLX_DIR)
	MLX_LIB	= mlx_$(UNAME)
	MLX_FLAGS = -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

CC			= cc
RM			= rm -f
# CFLAGS		= -Wall -Wextra -Werror -g
CFLAGS		= -g

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(@D)
			$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

.PHONY:		all bonus clean fclean re

all: 		$(NAME)

$(NAME): 	$(OBJS)
			@make -C $(LIBFT_DIR) all
			@make -C $(DPRINTF_DIR) all
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_FLAGS)

clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(DPRINTF_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			@make -C $(LIBFT_DIR) fclean
			@make -C $(DPRINTF_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all
