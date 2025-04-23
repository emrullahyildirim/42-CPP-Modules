NAME = FixedPoint
SOURCES = Fixed.cpp main.cpp  Point.cpp bsp.cpp
HEADERS = Fixed.hpp

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

clean: 
	echo "Nothing to clean!"

fclean:
	$(RM) $(NAME)

re: fclean all 
