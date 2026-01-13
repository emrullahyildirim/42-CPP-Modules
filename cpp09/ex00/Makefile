NAME = btc

SOURCES = main.cpp BitcoinExchange.cpp 
HEADERS = BitcoinExchange.hpp 

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