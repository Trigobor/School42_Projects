NAME	=	Unnecessary_violence
SRCS	=	main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
HEAD	=	HumanA.hpp HumanB.hpp
SDIR	=	./
FLAG	=	-Wall -Wextra -Werror
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
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re