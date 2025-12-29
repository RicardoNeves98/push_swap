/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:54:49 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/29 18:29:24 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				number;
	struct s_list	*next;
}	t_list;

// utils1_bonus.c
size_t	ft_strlen(const char *s);
char	*ft_calloc(size_t n);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_atoi(const char *nptr);
// utils2_bonus.c 
int		get_word_number(char const *s, char c);
int		alloc_words(char **lst, char const *s, char c);
char	**ft_split(char const *s, char c);
int		stack_size(t_list **stack);
void	free_stuff(char **list, t_list **stack, int argc);
// check_args_bonus.c 
int		ft_strcmp(const char *s1, const char *s2);
int		check_integer(char *num_str);
int		cmp_lim(char *num_str, int sign);
int		check_repetition(char **argc, int i);
int		check_list(char **argv, int argc, int i);
// moves1_bonus.c 
void	rotate_up(t_list **stack);
void	rotate_down(t_list **stack);
void	swap_first_two(t_list **stack);
void	push_sideways(t_list **get_stack, t_list **give_stack);
// moves2_bonus.c 
void	rotate_up_both(t_list **stack1, t_list **stack2);
void	rotate_down_both(t_list **stack1, t_list **stack2);
void	swap_first_two_both(t_list **stack1, t_list **stack2);
void	perform_move(t_list **stack1, t_list **stack2, char *move);
void	apply_move_list(t_list **stack1, t_list **stack2);
// checker_bonus.c
t_list	*initialize_struct(char **num_list, int argc);
t_list	*define_node(t_list *node, int number);
int		check_list(char **argv, int argc, int i);
void	check_stacks(t_list **stack1, t_list **stack2);

#endif
