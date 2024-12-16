SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = ClapTrap
CXX = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98

.cpp.o:
	@$(CXX) $(FLAGS) -c $< -o $(<:.cpp=.o)
	@printf "\033[32m[OK]\033[0m $<\n"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(FLAGS) $(OBJS) -o $(NAME)
	@printf "\033[32m[OK]\033[0m $(NAME)\n"

clean:
	@$(RM) $(OBJS)
	@printf "\033[32m[OK]\033[0m clean\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "\033[32m[OK]\033[0m fclean\n"

re: fclean all

.PHONY: all clean fclean re