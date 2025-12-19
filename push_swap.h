/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:47:27 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 19:00:43 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_list
{
	int		number;
	int		rank;
	int		diff;
	int		cost;
	int		move_type;
	int		node_ra;
	int		target_ra;
	struct s_list	*next;
}	t_list;

// utils1.c -> Helping functions from libft with minor alterations 
size_t  ft_strlen(const char *s);
int     ft_strcmp(const char *s1, const char *s2);
char    *ft_calloc(size_t n);
char    *ft_substr(char const *s, unsigned int start, size_t len);
int     ft_atoi(const char *nptr);

// utils2.c -> All the functions needed for split and to free stuff 
int     get_word_number(char const *s, char c);
int     alloc_words(char **lst, char const *s, char c);
char    **ft_split(char const *s, char c);
void	free_list(char **argv);
void	free_stack(t_list **stack);

// utils3.c -> Functions for to access stack info and max and min of numbers 
int     stack_size(t_list **stack);
int     get_last_rank(t_list **stack);
int	max(int number1, int number2);
int	min(int number1, int number2);

// check_args.c -> Check if the arguments given are correct 
int	check_integer(char *num_str);
int	cmp_lim(char *num_str, int sign);
int	check_repetition(char **argv, int i);

// swap_and_push.c -> Swap and Push moves  
void	swap_first_two(t_list **stack, char c);
void	push_sideways(t_list **get_stack, t_list **give_stack, char c);

// rotation_moves.c -> Rotation moves 
void    single_rotate_up(t_list **stack);
void    single_rotate_down(t_list **stack);
void	rotate_up(t_list **stack1, t_list **stack2);
void	rotate_down(t_list **stack1, t_list **stack2);

// get_cheapest.c -> Updating the cost of every node on stack1 
int	get_min_diff(t_list **stack, int start_value);
void	update_cost(t_list **stack1, t_list **stack2, int stack1_len, int stack2_len);
int	get_cheap_path(t_list *node1, int stack1_len, int stack2_len);
t_list	*get_cheap_node(t_list **stack1, t_list **stack2);

// move_cheapest.c -> Move the cheapest in stack A to its position in stack B 
void	move_cheap_node(t_list **stack1, t_list **stack2);
void	moves_type1(t_list *node, t_list **stack1, t_list **stack2);
void	moves_type2(t_list *node, t_list **stack1, t_list **stack2);
void	moves_type3(t_list *node, t_list **stack1, t_list **stack2);
void	moves_type4(t_list *node, t_list **stack1, t_list **stack2);

// algorithm.c -> Turk algorithm 
int     get_min_position(t_list **stack);
void    order_small(t_list **stack, char c);
void	rotate_stack(t_list **stack, int size);
void    back_to_stack(t_list **stack1, t_list **stack2);
void    order_stack(t_list **stack1, t_list **stack2);

// push_swap.c -> The main file containing the main and other important functions 
t_list  *initialize_struct(char **num_list, int argc); 
t_list  *define_node(t_list *node, int number); 
void    define_rank(t_list **stack, int list_len); 
int	check_list(char **argv, int argc, int i);

#endif
