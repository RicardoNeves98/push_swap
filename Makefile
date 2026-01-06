CFLAGS = -Wall -Wextra -Werror
NAME = push_swap 
BONUS = checker
SRCS = utils1.c utils2.c utils3.c swap_and_push_moves.c rotation_moves.c \
	push_swap.c move_cheap_node.c get_cheapest.c check_args.c algorithm.c 
SRCS_BONUS = utils1_bonus.c utils2_bonus.c utils3_bonus.c check_args_bonus.c moves1_bonus.c \
	moves2_bonus.c checker_bonus.c 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	cc $(CFLAGS) $(OBJS_BONUS) -o $(BONUS)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ 

.PHONY: bonus clean fclean re

clean: 
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all  
