# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eosfryd <eosfryd@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/10 19:21:41 by eosfryd           #+#    #+#              #
#    Updated: 2021/01/18 20:54:22 by eosfryd          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

NAME_LIBFT = libft.a

SRCS = ft_printf.c ft_parser_utils.c\
output/ft_strout_c.c output/ft_strout_s.c\
output/ft_strout_d.c output/ft_strout_utils.c output/ft_strout_p.c\
output/ft_strout_percent.c output/ft_strout_x.c output/ft_strout_u.c\
output/ft_itoa_ll.c\

OBJS = ${SRCS:.c=.o}

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_DIR = libft/

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			make -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)libft.a ./
			mv $(NAME_LIBFT) $(NAME)
			ar -rc $(NAME) ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		make fclean -C $(LIBFT_DIR)

re:	fclean all

.PHONY:	all clean fclean re
