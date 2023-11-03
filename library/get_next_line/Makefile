NAME		:= libgnl.a
SRCS		:= get_next_line.c \
			utils.c
LIBFT_DIR	:= ../libft

OBJS		:= ${SRCS:.c=.o}
LIBFT_OBJS	:= $(LIBFT_DIR)/*.o	

CC			= cc
AR			= ar
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -g -I$(LIBFT_DIR)
ARFLAGS		= -crs

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

.PHONY:		all clean fclean re

$(NAME):	${OBJS}
			${AR} ${ARFLAGS} ${NAME} ${OBJS} $(LIBFT_OBJS)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
