# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 19:21:41 by eosfryd           #+#    #+#              #
#    Updated: 2021/04/13 19:08:49 by eosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

NAME_LIBFT = libft.a

SRCS = sources/cub3d.c sources/screenpluserr.c sources/trashfunc.c sources/trashfunc2.c \
		sources/movement.c sources/directionwork.c sources/parcing.c sources/parcing2.c \
		sources/minimap.c sources/errors.c sources/funcpack.c sources/funcpack2.c

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft/

MLX = libmlx/libmlx.a -framework OpenGL -framework Appkit

$(NAME):	${OBJS} sources/cub3d.h
			make -C $(LIBFT_DIR)
			gcc ${CFLAGS} -o ${NAME} $(LIBFT_DIR)libft.a ${OBJS} ${MLX}

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
