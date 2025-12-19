/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:18 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 18:48:03 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_list **stack)
{
	int	min;
	int	count;
	int	position;
	t_list	*node;

	node = *stack;
	count = 1;
	position = 1;
	min = node->rank;
	while (node->next)
	{
		node = node->next;
		count++;
		if (node->rank < min)
		{
			min = node->rank;
			position = count;
		}
	}
	return (position);
}

void    order_small(t_list **stack, char c)
{
	int     min_position;

	min_position = get_min_position(stack);
	if (stack_size(stack) == 2 && min_position == 2)
        	swap_first_two(stack, c);
	else if (stack_size(stack) == 3)
	{
        	if (min_position == 1)
                	rotate_up(stack, NULL);
        	else if (min_position == 2)
                	rotate_down(stack, NULL);
        	if ((*stack)->number > ((*stack)->next)->number)
                	swap_first_two(stack, c);
        	rotate_down(stack, NULL);
	}
}

void    rotate_stack(t_list **stack, int size)
{
        int     ra_moves;
        int     rra_moves;

        ra_moves = get_min_position(stack);
        rra_moves = size - ra_moves;
        if (ra_moves < rra_moves)
                while (ra_moves--)
                        rotate_up(NULL, stack);
        else
                while (rra_moves--)
                        rotate_down(NULL, stack);
}

void	back_to_stack(t_list **stack1, t_list **stack2)
{
	int	last_rank;
	int	count;

	count = 0;
	last_rank = get_last_rank(stack1);
	while (*stack2)
	{
		while (*stack2 && last_rank < (*stack2)->rank)
			push_sideways(stack1, stack2, 'a');
		if (count < 3)
		{
			rotate_down(stack1, NULL);
			count++;
			if (count < 3)
				last_rank = get_last_rank(stack1);
			else
				last_rank = 0;
		}
	}
	while (count++ < 3)
		rotate_down(stack1, NULL);
}

void	order_stack(t_list **stack1, t_list **stack2)
{
	int	size1;
	int	size2;

	size1 = stack_size(stack1);
	size2 = stack_size(stack2);
	while (size1 > 3)
	{
		move_cheap_node(stack1, stack2);
		size1--;
		size2++;
	}
	if (size1 > 1)
		order_small(stack1, 'a');
	if (size2 == 0)
		return ;
	rotate_stack(stack2, size2);
	back_to_stack(stack1, stack2);
}
