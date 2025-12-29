/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 16:30:59 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/29 18:29:22 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_up_both(t_list **stack1, t_list **stack2)
{
	rotate_up(stack1);
	rotate_up(stack2);
}

void	rotate_down_both(t_list **stack1, t_list **stack2)
{
	rotate_down(stack1);
	rotate_down(stack2);
}

void	swap_first_two_both(t_list **stack1, t_list **stack2)
{
	swap_first_two(stack1);
	swap_first_two(stack2);
}

void    perform_move(t_list **stack1, t_list **stack2, char *move)
{
	if (!ft_strcmp(move, "sa"))
		swap_first_two(stack1);
	else if (!ft_strcmp(move, "sb"))
		swap_first_two(stack2);
	else if (!ft_strcmp(move, "ss"))
		swap_first_two_both(stack1, stack2);
	else if (!ft_strcmp(move, "pa"))
		push_sideways(stack1, stack2);
	else if (!ft_strcmp(move, "pb"))
		push_sideways(stack1, stack2);
	else if (!ft_strcmp(move, "ra"))
		rotate_up(stack1);
	else if (!ft_strcmp(move, "rb"))
		rotate_up(stack2);
	else if (!ft_strcmp(move, "rr"))
		rotate_up_both(stack1, stack2);
	else if (!ft_strcmp(move, "rra"))
		rotate_down(stack1);
	else if (!ft_strcmp(move, "rrb"))
		rotate_down(stack2);
	else if (!ft_strcmp(move, "rrr"))
		rotate_down_both(stack1, stack2);
}

void	apply_move_list(t_list **stack1, t_list **stack2)
{
	int             i;
	int             bytes_read;
	char    buffer[1024];
	char    *moves_str;
	char    **moves_lst;

	i = 0;
	moves_str = NULL;
	while (1)
	{
		bytes_read = read(0, buffer, sizeof(buffer));
		if (bytes_read <= 0)
			break ;
		moves_str = ft_strjoin(moves_str, buffer);
		if (!moves_str) // Think what it should return in case allocation fails 
		{
			free(moves_str);
			return ;
		}
	}
	moves_lst = ft_split(moves_str, ' ');
	while (!moves_lst[i])
	{
		perform_move(stack1, stack2, moves_lst[i++]);
		free(moves_lst[i]);
	}
	free(moves_lst);
}
