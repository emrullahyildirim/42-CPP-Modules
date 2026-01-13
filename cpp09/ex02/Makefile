NAME = PmergeMe

SOURCES = main.cpp PmergeMe.cpp 
HEADERS = PmergeMe.hpp 

CXX = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CXX) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean:
	echo "Nothing to clean."

fclean:
	$(RM) $(NAME)

re: fclean all 

.PHONY: all clean fclean re