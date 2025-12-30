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

char	**get_move_list(void)
{
	int		bytes_read;
	char	*buffer;
	char	*moves_str;
	char	**moves_lst;

	moves_str = NULL;
	while (1)
	{
		buffer = ft_calloc(42);
		if (!buffer)
			return (free(moves_str), NULL);
		bytes_read = read(0, buffer, 42);
		if (bytes_read <= 0)
		{
			if (bytes_read < 0)
				return (free(buffer), free(moves_str), NULL);
			free(buffer);
			break ;
		}
		moves_str = ft_strjoin(moves_str, buffer);
		if (!moves_str)
			return (NULL);
	}
	moves_lst = ft_split(moves_str, '\n');
	return (free(moves_str), moves_lst);
}

int	apply_move_list(t_list **stack1, t_list **stack2)
{
	int		i;
	char	**moves_lst;

	i = -1;
	moves_lst = get_move_list();
	if (!moves_lst)
		return (1);
	while (moves_lst[++i])
	{
		if (!perform_move(stack1, stack2, moves_lst[i]))
		{
			while (moves_lst[i])
				free(moves_lst[i++]);
			return (free(moves_lst), 0);
		}
		free(moves_lst[i]);
	}
	return (free(moves_lst), 1);
}
