NAME = buereaucratWithForm

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		Form.cpp 

HEADERS = Bureaucrat.hpp Form.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	echo "Nothing to clean."

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re