CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98
NAME = megaphone
RM = rm -rf

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CPPCOMPILER) $(CPPFLAGS) -o $(NAME) $(NAME).cpp

clean :
	$(RM) $(NAME)

re : clean all