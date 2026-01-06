/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 11:22:32 by rcarmo-n          #+#    #+#             */
/*   Updated: 2026/01/06 14:10:30 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i ++] - '0');
	return (sign * result);
}

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

void	free_stuff(char **list, t_list **stack, int argc)
{
	int		i;
	t_list	*next_node;

	i = 0;
	if (list && argc == 2)
	{
		while (list[i])
			free(list[i++]);
		free(list);
	}
	if (stack)
	{
		while (*stack)
		{
			next_node = (*stack)->next;
			free(*stack);
			*stack = next_node;
		}
	}
}
