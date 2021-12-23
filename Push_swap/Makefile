NAME = push_swap

NAME_LIBFT = libft.a

SRCS = main.c functions_pack_one.c functions_pack_two.c functions_pack_tree.c \
		functions_pack_four.c functions_pack_five.c functions_pack_six.c functions_pack_seven.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft/

$(NAME):	${OBJS} push_swap.h
			make -C $(LIBFT_DIR)
			gcc ${CFLAGS} -o ${NAME} $(LIBFT_DIR)libft.a ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}
		make clean -C $(LIBFT_DIR)

fclean:	clean
		${RM} ${NAME}
		make fclean -C $(LIBFT_DIR)

re:	fclean all clean
	${RM} ${OBJS}
	make clean -C $(LIBFT_DIR)

.PHONY:	re all clean fclean
