NAME = ZombieHorde
SOURCES = main.cpp Zombie.cpp zombieHorde.cpp

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