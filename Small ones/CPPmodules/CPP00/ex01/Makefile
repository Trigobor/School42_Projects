NAME	=	phonebook
SRCS	=	main.cpp PhoneBook.cpp Contact.cpp
SDIR	=	./
FLAG	=	-Wall -Wextra -Werror
ODIR	=	objects/
OBJS	=	$(addprefix $(ODIR), $(SRCS:.cpp=.o))
COMP	=	clang++

$(ODIR)%.o :	$(SDIR)%.cpp
	@mkdir -p $(ODIR)
	@$(COMP) $(FLAG) -c $< -o $@

$(NAME): $(OBJS)
	@$(COMP) $(FLAG) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	@rm -rf $(ODIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re