CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98 
NAME = phonebook
RM = rm -rf

SRCS = main.cpp Contact.cpp Phonebook.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPPCOMPILER) $(CPPFLAGS) -o $(NAME) $(OBJS) 
	chmod +x $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.cpp
	$(CPPCOMPILER) $(CPPFLAGS) -c $< -o $@