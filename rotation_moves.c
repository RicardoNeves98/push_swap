/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possible_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:49:20 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 17:24:45 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotate_up(t_list **stack)
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

void	single_rotate_down(t_list **stack)
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

void	rotate_up(t_list **stack1, t_list **stack2)
{
	if (!stack1 && !stack2)
		return ;
	else if (stack1 && !stack2)
	{
		single_rotate_up(stack1);
		write(1, "ra\n", 3);
	}
	else if (!stack1 && stack2)
	{
		single_rotate_up(stack2);
		write(1, "rb\n", 3);
	}
	else if (stack1 && stack2)
	{
		single_rotate_up(stack1);
		single_rotate_up(stack2);
		write(1, "rr\n", 3);
	}
}

void	rotate_down(t_list **stack1, t_list **stack2)
{
	if (!stack1 && !stack2)
		return ;
	else if (stack1 && !stack2)
	{
		single_rotate_down(stack1);
		write(1, "rra\n", 4);
	}
	else if (!stack1 && stack2)
	{
		single_rotate_down(stack2);
		write(1, "rrb\n", 4);
	}
	else if (stack1 && stack2)
	{
		single_rotate_down(stack1);
		single_rotate_down(stack2);
		write(1, "rrr\n", 4);
	}
}
