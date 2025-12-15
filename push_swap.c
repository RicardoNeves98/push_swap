/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:21:47 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/15 20:00:20 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize_struct(char **num_list, int argc)
{
	int	i;
	t_list	*first_node;
	t_list	*node;

	i = 0;
	if (argc > 2)
		i = 1;
	node = define_first_node(ft_atoi(num_list[i++]));
	if (!node)
		return (free_list(num_list), NULL);
	first_node = node;
	while (num_list[i])
	{
		node = define_node(node, ft_atoi(num_list[i++]));
		if (!node)
			return (free_list(num_list), free_stack(&first_node), NULL);
	}
	node->next = NULL;
	return (first_node);
}

t_list	*define_first_node(int number)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->number = number;
	node->rank = -1;
	node->next = NULL;
	return (node);
}

t_list	*define_node(t_list *node, int number)
{
	t_list	*next_node;

	next_node = malloc(sizeof(t_list));
	if (!next_node)
		return (NULL);
	next_node->number = number;
	next_node->rank = -1;
	next_node->next = NULL;
	node->next = next_node;
	return (next_node);
}

void	define_rank(t_list **stack, int list_len)
{
	int	rank;
	t_list	*node;
	t_list	*min_node;
	t_list	*next_node;

	rank = 0;
	while (rank < list_len)
	{
		node = *stack;
		while (node->rank != -1)
			node = node->next;
		min_node = node;
		while (node)
		{
			next_node = node->next;
			if (next_node && next_node->rank == -1 && 
				next_node->number < min_node->number)
				min_node = next_node;
			node = next_node;
		}	
		min_node->rank = rank;
		rank++;
	}
}

void	print_numbers(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node)
	{
		printf("%d has rank %d\n", node->number, node->rank);
		node = node->next;
	}
}

int     main(int argc, char **argv)
{
	int	i;
	int	list_len;
	t_list	*first_node;

        i = 0;
	list_len = argc - 1;
        if (argc == 1)
                return (0);
        else if (argc == 2)
        {
		list_len = numbers_count(argv[1]);
                argv = ft_split(argv[1], ' ');
                i = -1;
        }
        while (argv[++i])
        {
                if (!check_integer(argv[i]) || !check_repetition(argv, i))
                {
                        if (argc == 2)
                                free_list(argv);
                        write(1, "Error", 5);
                        return (0);
                }
        }
        first_node = initialize_struct(argv, argc);
	define_rank(&first_node, list_len);
	print_numbers(&first_node);
	if (argc == 2)
		free_list(argv);
	free_stack(&first_node);
        return (0);
}
