/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cost.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:46:18 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/17 19:51:47 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     get_min_diff(t_list **stack, int start_value)
{
	int     min;
	int     count;
	int     position;
	t_list  *node;

	node = *stack;
	count = 0;
	position = start_value;
	min = start_value;
	while (node)
	{
		if (node->diff > 0 && node->diff < min)
		{
			min = node->diff;
			position = count;
		}
		node = node->next;
		count++;
	}
	return (position);
}

/*
total1 -> Total moves using normal rotation on both stack  
total2 -> Total moves using reverse rotation on both stack 
total3 -> Total moves using normal rotation on stack A and reverse rotation on stack B  
total4 -> Total moves using reverse rotation on stack A and reverse rotation on stack B 
*/
int     get_min_cost(int stack1_len, int stack2_len, int moves_node1, int moves_node2)
{
	int     total1;
	int     total2;
	int     total3;
	int     total4;

	total1 = MAX(moves_node1, moves_node2);
	total2 = MAX(stack1_len - moves_node1, stack2_len - moves_node2);
	total3 = moves_node1 + (stack2_len - moves_node2);
	total4 = (stack1_len - moves_node1) + moves_node2;
	return (MIN(MIN(total1, total2), MIN(total3, total4)));
}
 	
void    update_cost(t_list **stack1, t_list **stack2, int stack1_len, int stack2_len)
{
	int     moves_node1;
	int     moves_node2;
	t_list  *node1;
	t_list  *node2;

	node1 = *stack1;
	moves_node1 = 0;
	while (node1)
	{
		node2 = *stack2;
		while (node2)
		{
			node2->diff = node1->rank - node2->rank;
			node2 = node2->next;
		}
		moves_node2 = get_min_diff(stack2, stack1_len + stack2_len + 1);
		if (moves_node2 == stack1_len + stack2_len + 1)
			moves_node2 = get_min_position(stack2, 
				stack1_len + stack2_len + 1) - 1;
		node1->cost = get_min_cost(stack1_len, stack2_len, moves_node1, moves_node2);
		node1 = node1->next;
		moves_node1++;
	}
}
