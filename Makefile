CC			= cc
CFLAGS		= -Wextra -Wall -Werror -g
NAME		= push_swap
SRCS		= main.c compute.c simple_algorithm.c mid_algo.c bucket.c init.c check_input.c \
			  utils.c utils2.c utils3.c utils4.c utils5.c \
			  operators_s_.c operators_p_.c operators_r_.c operators_rr_.c operators.c \
			  ft_printf.c ft_printf_utils1.c ft_printf_utils2.c \
			  display.c
OBJS		= $(SRCS:.c=.o)
HEADERS		= push_swap.h stack.h operators.h result.h ft_printf.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re