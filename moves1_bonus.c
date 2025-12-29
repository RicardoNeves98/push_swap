/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:15:42 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/29 16:34:47 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_up(t_list **stack)
{
	t_list  *node1;
	t_list  *last_node;

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
	t_list  *prev_last_node;
	t_list  *last_node;

	prev_last_node = *stack;
	while ((prev_last_node->next)->next)
		prev_last_node = prev_last_node->next;
	last_node = prev_last_node->next;
	prev_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	swap_first_two(t_list **stack)
{
	t_list  *node2;
	t_list  *node3;

	if (stack_size(stack) < 2)
		return ;
	node2 = (*stack)->next;
	node3 = ((*stack)->next)->next;
	node2->next = *stack;
	(*stack)->next = node3;
	*stack = node2;
}

void    push_sideways(t_list **get_stack, t_list **give_stack)
{
	t_list  *give_node2;

	if (!(*give_stack))
		return ;
	give_node2 = (*give_stack)->next;
	(*give_stack)->next = *get_stack;
	*get_stack = *give_stack;
	*give_stack = give_node2;
}
