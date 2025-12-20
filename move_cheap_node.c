/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:13:31 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 17:54:42 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheap_node(t_list **stack1, t_list **stack2)
{
	int		size2;
	t_list	*cheap_node;

	size2 = stack_size(stack2);
	cheap_node = NULL;
	if (size2 > 1)
		cheap_node = get_cheap_node(stack1, stack2);
	else
	{
		push_sideways(stack2, stack1, 'b');
		if (size2 == 1)
			order_small(stack2, 'b');
		return ;
	}
	if (cheap_node->move_type == 1)
		moves_type1(cheap_node, stack1, stack2);
	else if (cheap_node->move_type == 2)
		moves_type2(cheap_node, stack1, stack2);
	else if (cheap_node->move_type == 3)
		moves_type3(cheap_node, stack1, stack2);
	else if (cheap_node->move_type == 4)
		moves_type4(cheap_node, stack1, stack2);
	push_sideways(stack2, stack1, 'b');
}

void	moves_type1(t_list *node, t_list **stack1, t_list **stack2)
{
	int	rr_moves;
	int	ra_moves;
	int	rb_moves;

	rr_moves = min(node->node_ra, node->target_ra);
	ra_moves = node->node_ra - node->target_ra;
	rb_moves = 0;
	if (ra_moves < 0)
	{
		rb_moves = -ra_moves;
		ra_moves = 0;
	}
	while (rr_moves--)
		rotate_up(stack1, stack2);
	while (ra_moves--)
		rotate_up(stack1, NULL);
	while (rb_moves--)
		rotate_up(NULL, stack2);
}

void	moves_type2(t_list *node, t_list **stack1, t_list **stack2)
{
	int	size1;
	int	size2;
	int	rrr_moves;
	int	rrb_moves;
	int	rra_moves;

	size1 = stack_size(stack1);
	size2 = stack_size(stack2);
	rrr_moves = min(size1 - node->node_ra, size2 - node->target_ra);
	rra_moves = (size1 - node->node_ra) - (size2 - node->target_ra);
	rrb_moves = 0;
	if (rra_moves < 0)
	{
		rrb_moves = -rra_moves;
		rra_moves = 0;
	}
	while (rrr_moves--)
		rotate_down(stack1, stack2);
	while (rra_moves--)
		rotate_down(stack1, NULL);
	while (rrb_moves--)
		rotate_down(NULL, stack2);
}

void	moves_type3(t_list *node, t_list **stack1, t_list **stack2)
{
	int	size2;
	int	ra_moves;
	int	rrb_moves;

	size2 = stack_size(stack2);
	ra_moves = node->node_ra;
	rrb_moves = size2 - node->target_ra;
	while (ra_moves--)
		rotate_up(stack1, NULL);
	while (rrb_moves--)
		rotate_down(NULL, stack2);
}

void	moves_type4(t_list *node, t_list **stack1, t_list **stack2)
{
	int	size1;
	int	rra_moves;
	int	rb_moves;

	size1 = stack_size(stack1);
	rra_moves = size1 - node->node_ra;
	rb_moves = node->target_ra;
	while (rra_moves--)
		rotate_down(stack1, NULL);
	while (rb_moves--)
		rotate_up(NULL, stack2);
}
