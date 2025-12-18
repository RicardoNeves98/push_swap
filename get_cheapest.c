/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheapest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:55:55 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 18:48:16 by rcarmo-n         ###   ########.fr       */
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
int     get_node_cheapest_path(t_list *node1, int stack1_len, int stack2_len)
{
	int     total1;
	int     total2;
	int     total3;
	int     total4;
	int	min_total;

	total1 = MAX(node1->node_ra, node1->target_ra);
	total2 = MAX(stack1_len - node1->node_ra, stack2_len - node1->target_ra);
	total3 = node1->node_ra + (stack2_len - node1->target_ra);
	total4 = (stack1_len - node1->node_ra) + node1->target_ra;
	min_total = MIN(MIN(total1, total2), MIN(total3, total4));
	if (total1 == min_total)
		node1->move_type = 1;
	else if (total2 == min_total)
		node1->move_type = 2;
	else if (total3 == min_total)
		node1->move_type = 3;
	else if (total4 == min_total)
		node1->move_type = 4;
	return (min_total);
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
			moves_node2 = get_min_position(stack2);
		node1->node_ra = moves_node1;
		node1->target_ra = moves_node2;
		node1->cost = get_node_cheapest_path(node1, stack1_len, stack2_len);
		node1 = node1->next;
		moves_node1++;
	}
}

t_list	*get_cheapest_node(t_list **stack1, t_list **stack2)
{
	int     min;
	int	size1;
	int	size2;
	t_list	*node;
	t_list  *min_node;

	size1 = stack_size(stack1);
	size2 = stack_size(stack2);
	node = *stack1;
	min_node = node;
        update_cost(stack1, stack2, size1, size2);
	min = node->cost;
	while (node->next)
	{
		if (min == 0)
			return (min_node);
		node = node->next;
		if (node->cost < min)
			min_node = node;
	}
	return (min_node);
}
