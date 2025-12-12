/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:47:27 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 18:25:38 by rcarmo-n         ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

// check_args.c -> Check if the arguments given are correct  
int	check_integer(char *num_str);
int	cmp_lim(char *num_str, int sign);	
int	check_repetition(char **argv, int i);
// free_stuff.c -> Free list 
void	free_list(char **argv);
void	free_stack(t_list **stack);
// possible_moves.c -> All the moves that are allowed with the struct 
void	swap_first_two(t_list **stack);
void	push_sideways(t_list **stack_a, t_list **stack_b);
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
void	print_number(t_list **stack);

#endif
