/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:21:47 by rcarmo-n          #+#    #+#             */
/*   Updated: 2026/01/06 15:26:27 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize_struct(char **num_list, int argc)
{
	int		i;
	t_list	*first_node;
	t_list	*node;

	i = 0;
	if (argc > 2)
		i = 1;
	if (!num_list[i])
		return (free_stuff(num_list, NULL, argc), NULL);
	node = define_node(NULL, ft_atoi(num_list[i++]));
	if (!node)
		return (free_stuff(num_list, NULL, argc), NULL);
	first_node = node;
	while (num_list[i])
	{
		node = define_node(node, ft_atoi(num_list[i++]));
		if (!node)
			return (free_stuff(num_list, &first_node, argc), NULL);
	}
	node->next = NULL;
	return (first_node);
}

t_list	*define_node(t_list *node, int number)
{
	t_list	*next_node;

	next_node = malloc(sizeof(t_list));
	if (!next_node)
		return (NULL);
	next_node->number = number;
	next_node->rank = 0;
	next_node->diff = 0;
	next_node->cost = 0;
	next_node->move_type = 0;
	next_node->node_ra = 0;
	next_node->target_ra = 0;
	next_node->next = NULL;
	if (node)
		node->next = next_node;
	return (next_node);
}

void	define_rank(t_list **stack, int list_len)
{
	int		rank;
	t_list	*node;
	t_list	*min_node;
	t_list	*next_node;

	rank = 1;
	while (rank <= list_len)
	{
		node = *stack;
		while (node->rank != 0)
			node = node->next;
		min_node = node;
		while (node)
		{
			next_node = node->next;
			if (next_node && next_node->rank == 0
				&& next_node->number < min_node->number)
				min_node = next_node;
			node = next_node;
		}
		min_node->rank = rank;
		rank++;
	}
}

int	check_list(char **argv, int argc, int i)
{
	int	check;

	check = 1;
	if (argc == 2 && !argv[0])
		check = 0;
	while (argv[++i])
	{
		if (!check_integer(argv[i]) || !check_repetition(argv, i))
		{
			check = 0;
			break ;
		}
	}
	if (check == 0)
	{
		free_stuff(argv, NULL, argc);
		write(2, "Error\n", 6);
	}
	return (check);
}

int	main(int argc, char **argv)
{
	int		i;
	int		list_len;
	t_list	*stack1_head;
	t_list	*stack2_head;

	i = 0;
	list_len = argc - 1;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		list_len = get_word_number(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (!check_list(argv, argc, i))
		return (0);
	stack1_head = initialize_struct(argv, argc);
	if (!stack1_head)
		return (0);
	stack2_head = NULL;
	define_rank(&stack1_head, list_len);
	order_stack(&stack1_head, &stack2_head);
	free_stuff(argv, &stack1_head, argc);
	return (0);
}
