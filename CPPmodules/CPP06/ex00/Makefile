NAME	=	Scalar_conversion
SRCS	=	main.cpp Convertion.cpp
SDIR	=	./
FLAG	=	-Wall -Wextra -Werror
HEAD	=	Convertion.hpp
ODIR	=	objects/
OBJS	=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
COMP	=	clang++

$(ODIR)%.o :	$(SDIR)%.cpp
	@mkdir -p $(ODIR)
	@$(COMP) $(FLAG) -c $< -o $@

$(NAME): $(OBJS) $(HEAD)
	@$(COMP) $(FLAG) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(ODIR) *.replace

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re