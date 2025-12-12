/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 15:21:47 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 18:53:18 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*initialize_struct(char **num_list, int argc)
{
	int	i;
	t_list	*first_node;
	t_list	*node;
	t_list	*next_node;

	i = 0;
	if (argc > 2)
		i = 1;
	node = malloc(sizeof(t_list));
	if (!node)
	{
		free_list(num_list);
		return (NULL);
	}
	node->number = ft_atoi(num_list[i++]);
	node->next = NULL;
	first_node = node;
	while (num_list[i])
	{
		next_node = malloc(sizeof(t_list));
		if (!next_node)
		{
			free_list(num_list);
			free_stack(&first_node);
			return(NULL);
		}
		next_node->number = ft_atoi(num_list[i++]);
		next_node->next = NULL;
		node->next = next_node;
		node = next_node;
	}
	node->next = NULL;
	if (argc == 2)
		free_list(num_list);
	return (first_node);
}

void	print_numbers(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node)
	{
		printf("%d \n", node->number);
		node = node->next;
	}
}

int     main(int argc, char **argv)
{
	t_list	*first_node;
        int     i;

        i = 0;
        if (argc == 1)
                return (0);
        else if (argc == 2)
        {
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
	
//	Testing the functions I created to move then nodes:
	printf("Initial Order:\n");
	print_numbers(&first_node);
//	Rotating Down 
	rotate_down(&first_node);
	printf("Order After Rotate Down:\n");
	print_numbers(&first_node);
//	Swaping First Two 
	swap_first_two(&first_node);
	printf("Order After Swap:\n");
	print_numbers(&first_node);
//	Rotating Up 
	rotate_up(&first_node);
	printf("Order After Rotate Up:\n");
	print_numbers(&first_node);
	
	free_stack(&first_node);
        return (0);
}
