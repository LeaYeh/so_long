NAME		:= lib42.a
LIBFT_DIR	:= libft
PRINTF_DIR	:= ftprintf
GNL_DIR		:= get_next_line
BUILD_DIR	:= build

AR_FILES	:= $(BUILD_DIR)/libft.a \
			$(BUILD_DIR)/libftprintf.a \
			$(BUILD_DIR)/libgnl.a

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

clean:
			@make -C $(LIBFT_DIR) clean
			@make -C $(PRINTF_DIR) clean
			@make -C $(GNL_DIR) clean
			$(RM) -r $(BUILD_DIR)

fclean:
			@make -C $(LIBFT_DIR) fclean
			@make -C $(PRINTF_DIR) fclean
			@make -C $(GNL_DIR) fclean
			$(RM) -r $(BUILD_DIR)
			$(RM) $(NAME)

re: fclean all
