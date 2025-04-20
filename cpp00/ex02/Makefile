NAME = Account

SOURCES = Account.cpp tests.cpp
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(SOURCES) $(CPPFLAGS) -o $(NAME)

clean: 
	echo "Nothin to remove."

fclean: 
	$(RM) $(NAME)

re: fclean all
	