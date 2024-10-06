CPPCOMPILER = c++
CPPFLAGS = -Werror -Wextra -Wall -std=c++98 
NAME = account
RM = rm -rf

SRCS = tests.cpp Account.cpp
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