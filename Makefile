CFLAGS = -Wall -Wextra -Werror
NAME = push_swap 

SRCS = utils1.c utils2.c utils3.c swap_and_push_moves.c rotation_moves.c \
	push_swap.c move_cheap_node.c get_cheapest.c check_args.c algorithm.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ 

.PHONY: clean fclean re

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) 

re: fclean all 
