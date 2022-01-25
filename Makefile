
NAME 		= ft_printf
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
EXTRA_FLAGS = -Wpedantic -Wunused -Wconversion -Wunreachable-code -Wtype-limits
SRCS		= main.c ft_printf.c
SRCS_DIR	= ./sources/
OBJS		= $(addprefix	$(OBJS_DIR), $(SRCS:.c=.o))
OBJS_DIR	= ./objects/
LIBFLAGS	= -L libft -lft
INCLUDES	= -I includes -I libft/includes

all: $(NAME)

$(NAME): $(OBJS)

	$(CC) $(CFLAGS) $(EXTRA_FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(LIBFLAGS)

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
#	make -sC libft
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	rm -rf $(OBJS_DIR)
#	rm -f libft/objects/*.o

fclean: clean
	rm -f $(NAME)
#	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re