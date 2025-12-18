/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:18 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/17 19:51:47 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_position(t_list **stack, int start_value)
{
	int	min;
	int	count;
	int	position;
	t_list	*node;

	node = *stack;
	count = 1;
	position = 1;
	min = start_value;
	while (node)
	{
		if (node->rank < min)
		{
			min = node->rank;
			position = count;
		}
		node = node->next;
		count++;
	}
	return (position);
}

void    order_small(t_list **stack)
{
	int     min_position;
	
	min_position = get_min_position(stack, stack_size(stack) + 1);
	if (stack_size(stack) == 2 && min_position == 2)
        	swap_first_two(stack);
	else if (stack_size(stack) == 3)
	{
        	if (min_position == 1)
                	rotate_up(stack);
        	else if (min_position == 2)
                	rotate_down(stack);
        	if ((*stack)->number > ((*stack)->next)->number)
                	swap_first_two(stack);
        	rotate_down(stack);
	}
}
