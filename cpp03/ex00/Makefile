NAME = ClapTrap
SOURCES = main.cpp ClapTrap.cpp
HEADERS = ClapTrap.hpp

CPPC=c++
CPPFLAGS= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CPPC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean: 
	echo "Nothing to clean!"

fclean: 
	$(RM) $(NAME)

re: fclean all