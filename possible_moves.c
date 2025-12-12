/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:49:20 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 18:12:24 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_list **stack)
{
	t_list	*node2;
	t_list	*node3;

//	if (list_len(stack) < 2)
//		return ;
	node2 = (*stack)->next;
	node3 = ((*stack)->next)->next;
	node2->next = *stack;
	(*stack)->next = node3;
	*stack = node2;
}

// push head of stact_b to stack_a 
void	push_sideways(t_list **stack_a, t_list **stack_b)
{
	t_list	*node2_b;

	if (!(*stack_b))
		return ;
	node2_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
	*stack_a = *stack_b;
	*stack_b = node2_b;
}

void	rotate_up(t_list **stack)
{
	t_list	*node1;
	t_list	*last_node;
	
	node1 = *stack;
	last_node = *stack;
	*stack = (*stack)->next;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = node1;
	node1->next = NULL;
}

void	rotate_down(t_list **stack)
{
	t_list	*prev_last_node;
	t_list	*last_node;

	prev_last_node = *stack;
	while ((prev_last_node->next)->next)
		prev_last_node = prev_last_node->next;
	last_node = prev_last_node->next;
	prev_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}
