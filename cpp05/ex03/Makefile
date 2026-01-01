NAME = internWithCoolForms

CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp

HEADERS = Bureaucrat.hpp AForm.hpp \
		  ShrubberyCreationForm.hpp \
		  RobotomyRequestForm.hpp \
		  PresidentialPardonForm.hpp \
		  Intern.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADERS)
	$(CC) $(CPPFLAGS) $(SRCS) -o $(NAME)

clean:
	echo "Nothing to clean."

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re