NAME = philo

SRCS = main.c utils_and_parce.c checkers_and_stuff.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME):	${OBJS} philo.h
			gcc ${CFLAGS} -o ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all clean
	${RM} ${OBJS}

.PHONY:	re all clean fclean
