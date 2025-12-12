/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:30:13 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 18:45:35 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_list(char **list)
{
        int     i;

        i = 0;
        while (list[i])
                free(list[i++]);
        free(list);
}

void	free_stack(t_list **stack)
{
	t_list	*next_node;

	while (*stack)
	{
		next_node = (*stack)->next;
		free(*stack);
		*stack = next_node;
	}		
}
