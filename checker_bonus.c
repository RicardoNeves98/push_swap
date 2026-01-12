/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:21:47 by rcarmo-n          #+#    #+#             */
/*   Updated: 2026/01/12 14:29:43 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	next_node->next = NULL;
	if (node)
		node->next = next_node;
	return (next_node);
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

void	check_stacks(t_list **stack1, t_list **stack2)
{
	int	curr_num;

	if (*stack2)
	{
		write(2, "KO\n", 3);
		return ;
	}
	curr_num = (*stack1)->number;
	while ((*stack1)->next)
	{
		*stack1 = (*stack1)->next;
		if ((*stack1)->number < curr_num)
		{
			write(2, "KO\n", 3);
			return ;
		}
		curr_num = (*stack1)->number;
	}
	write(1, "OK\n", 3);
	return ;
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack1_head;
	t_list	*stack2_head;

	i = 0;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (!check_list(argv, argc, i))
		return (0);
	stack1_head = initialize_struct(argv, argc);
	if (!stack1_head)
		return (0);
	stack2_head = NULL;
	if (!apply_move_list(&stack1_head, &stack2_head))
		return (write(2, "Error\n", 6), 0);
	check_stacks(&stack1_head, &stack2_head);
	free_stuff(argv, &stack1_head, argc);
	return (0);
}
