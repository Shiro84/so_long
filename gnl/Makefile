NAME = gnl.a

SRCS = get_next_line_bonus.c\
		get_next_line_utils_bonus.c\
		get_next_line_utils.c\
		get_next_line.c

HEADER = -I
OBJECTS = $(SRCS:.c=.o)
DEPENDENCIAS = $(SRCS:.c=.d)

CFLAGS = -Wall -Wextra -Werror -g

DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m
PURPLE = \033[0;95m

all: $(NAME)

-include $(DEPENDENCIAS)

$(NAME): $(OBJECTS)
	@ar -rcs $(NAME) $(OBJECTS)

%.o: %.c
	@$(CC) -MMD $(CFLAGS) -I ./ -c $< -o $@

clean:
	@rm -rf $(DEPENDENCIAS)
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re