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

int	get_min_position(t_list **stack)
{
	int	min;
	int	count;
	int	position;
	t_list	*node;

	node = *stack;
	count = 1;
	position = 1;
	min = (node)->number;
	while (node->next)
	{
		node = node->next;
		count++;
		if (node->number < min)
		{
			min = node->number;
			position = count;
		}
	}
	return (position);
}

void    order_small(t_list **stack)
{
        int     min_position;
	
	min_position = get_min_position(stack);
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

void	update_cost(t_list **stack1, t_list **stack2, int stack1_len, int stack2_len)
{
	int	moves_node1;
	int	moves_node2;
	t_list	*node1;
	t_list	*node2;
	
	node1 = *stack1;
	moves_node1 = 0;	
	while (node1)
	{
		node2 = *stack2;
		moves_node2 = 0;
		while (node2 && (node1->number < node2->number))
		{
			moves_node2++;
			node2 = node2->next;
		}
		if (!node2)
			moves_node2 = 0;
		node1->cost = get_min_cost(stack1_len, stack2_len, moves_node1, moves_node2)
		node1 = node1->next;
}

// type1 -> On both stacks going to do normal rotation 
// type2 -> On both stacks going to do reverse rotation 
// type3 -> On stack A normal rotation and on stack B reverse rotation 
// type4 -> On stack A reverse rotation and on stack A normal rotation
int	get_min_cost(node1, int stack1_len, int stack2_len, int moves_node1, int moves_node2)
{
	int	type1;
	int	type2;
	int	type3;
	int	type4;
	int	min_type;

	type1 = MAX(moves_node1, moves_node2);
	type2 = MAX(stack1_len - moves_node1, stack2_len - moves_node2);
	type3 = moves_node1 + (stack2_len - moves_node2);
	type4 = (stack1_len - moves_node1) + moves_node2;
	min_type = MIN(MIN(type1, type2), MIN(type3, type4));
	(node1->cost_list)->total_moves = 
	if (type1 == min_type)
		
}

/*
Lets see all the possibilities:
Need to get both node1 and node2 to the top:
(1) Share movements with rotation 
Then the total amount of moves would be the max of moves_node1 and moves_node2
(2) Share movements with reverse rotation 
Then the total amount of moves would be the max of stack1_len - moves_node1 and stack2_len - moves_node2
(3) Rotation with node1 and reverse rotation with node2
Then the total amount of moves would be the moves_node1 plus stack2_len - moves_node2
(4) Reverse rotation with node1 and rotation with node2
Then the total amount of moves would be the stack2_len - moves_node1 plus moves_node2
*/

void	get_in_order(t_list **stacka, t_list **stackb)
{
	int	original_size;

	original_size = stack_size(stacka);
	while (original_size--)
	{
		
	}
}
