NAME = ZombieHorde
SOURCES = main.cpp Zombie.cpp zombieHorde.cpp

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(SOURCES) $(CPPFLAGS) -o $(NAME)

clean:
	echo "Nothing to clean.."

fclean:
	$(RM) $(NAME)

re: fclean all