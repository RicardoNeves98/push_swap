/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:27 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 18:11:53 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_list **stack)
{
	int		count;
	t_list	*node;

	count = 0;
	node = *stack;
	while (node)
	{
		count++;
		node = (node)->next;
	}
	return (count);
}

int	get_last_rank(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next)
		node = node->next;
	return (node->rank);
}

int	max(int number1, int number2)
{
	if (number1 > number2)
		return (number1);
	return (number2);
}

int	min(int number1, int number2)
{
	if (number1 < number2)
		return (number1);
	return (number2);
}
