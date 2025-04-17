NAME = Harl
SOURCES = main.cpp Harl.cpp

CC = c++
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(SOURCES) $(CPPFLAGS) -o $(NAME)

clean:
	echo "Nothing to clean.."

fclean:
	$(RM) -f $(NAME)

re: fclean all