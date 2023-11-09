NAME		:= lib42.a
LIBFT_DIR	:= libft
PRINTF_DIR	:= ftprintf
GNL_DIR		:= get_next_line
BUILD_DIR	:= build

AR_FILES	:= $(BUILD_DIR)/libft.a \
			$(BUILD_DIR)/libftprintf.a \
			$(BUILD_DIR)/libgnl.a

MLX_DIR		:= mlx
UNAME		:= $(shell uname)
ifeq ($(UNAME), Linux)
	MLX_BUILD_DIR	= minilibx_linux
	INCLUDES 		+= -I/usr/include -I$(MLX_DIR)
	MLX_LIB			= mlx
	MLX_LIB_PATH	= $(MLX_BUILD_DIR)/libmlx.a
	MLX_FLAGS 		= -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/lib/X11 -lXext -lX11
else
	MLX_BUILD_DIR	= minilibx_macos
	INCLUDES 		+= -I/opt/X11/include -I$(MLX_DIR)
	MLX_LIB			= mlx.dylib
	MLX_LIB_PATH	= $(MLX_BUILD_DIR)/libmlx.dylib
	MLX_FLAGS 		= -L$(MLX_DIR) -l$(MLX_LIB) -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
endif

AR			= ar
RM			= rm -f

ARFLAGS		= -crs

.PHONY:		all clean fclean re

all:		$(NAME)

$(NAME):	premake $(AR_FILES)
			$(AR) $(ARFLAGS) $(NAME) $(AR_FILES)

premake:	
			@make -C $(LIBFT_DIR) bonus
			@make -C $(PRINTF_DIR) all
			@make -C $(GNL_DIR) all
			@mkdir -p $(BUILD_DIR)
			@cp $(LIBFT_DIR)/*.a $(PRINTF_DIR)/*.a $(GNL_DIR)/*.a $(BUILD_DIR)
			@cp $(LIBFT_DIR)/libft.h $(PRINTF_DIR)/includes/ft_printf.h $(GNL_DIR)/get_next_line.h $(BUILD_DIR)
			@make -C $(MLX_BUILD_DIR) all
			@mkdir -p $(MLX_DIR)
			@cp $(MLX_LIB_PATH) $(MLX_BUILD_DIR)/mlx.h $(MLX_DIR)

clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean
			@make -C $(GNL_DIR) clean
			@make -C $(MLX_BUILD_DIR) clean
			$(RM) -r $(BUILD_DIR)
			$(RM) -rf $(MLX_DIR)

fclean:
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean
			@make -C $(GNL_DIR) fclean
			@make -C $(MLX_BUILD_DIR) fclean
			$(RM) -r $(BUILD_DIR)
			$(RM) -rf $(MLX_DIR)
			$(RM) $(NAME)

re: fclean all
