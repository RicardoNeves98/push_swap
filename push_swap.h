/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:47:27 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/17 19:51:06 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	cost
{
	int	total_moves;
	int	type;
}	cost;

typedef struct	s_list
{
	int		number;
	int		rank;
	struct cost	cost_list;
	struct s_list	*next;
}	t_list;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

// check_args.c -> Check if the arguments given are correct  
int	check_integer(char *num_str);
int	cmp_lim(char *num_str, int sign);	
int	check_repetition(char **argv, int i);
// free_stuff.c -> Free list 
void	free_list(char **argv);
void	free_stack(t_list **stack);
// possible_moves.c -> All the moves that are allowed with the struct 
int	stack_size(t_list **stack);
void	swap_first_two(t_list **stack);
void	push_sideways(t_list **get_stack, t_list **give_stack);
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);
// utils1.c -> Helping functions from libft with minor alterations 
size_t	ft_strlen(const char *s);
int	ft_strcmp(const char *s1, const char *s2);
char	*ft_calloc(size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int	ft_atoi(const char *nptr);
// utils2.c -> ft_split 
int	get_word_number(char const *s, char c);
int	alloc_words(char **lst, char const *s, char c);
char	**ft_split(char const *s, char c);
// push_swap.c -> The main file containing the main and other important functions 
t_list	*initialize_struct(char **num_list, int argc);
t_list	*define_first_node(int number);
t_list	*define_node(t_list *node, int number);
void	define_rank(t_list **stack, int list_len);
void	print_numbers(t_list **stack);
// algorithm.c -> Turk algorithm 
int	get_min_number_node(t_list **stack);
void	order_small(t_list **stack);
void	get_in_order(t_list **stacka, t_list **stackb);

#endif
