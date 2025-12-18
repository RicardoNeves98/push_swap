/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:08:27 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/18 18:11:53 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This file only contains ft_split function 
int	get_word_number(char const *s, char c)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c)
			index ++;
		if (s[index])
		{
			count ++;
			while (s[index] && s[index] != c)
				index ++;
		}
	}
	return (count);
}

int	alloc_words(char **lst, char const *s, char c)
{
	unsigned int	index1;
	size_t			index2;
	int				lst_index;	

	lst_index = 0;
	index1 = 0;
	while (s[index1])
	{
		while (s[index1] == c)
			index1 ++;
		index2 = 0;
		if (s[index1])
		{
			while (s[index1 + index2] && s[index1 + index2] != c)
				index2 ++;
			lst[lst_index] = ft_substr(s, index1, index2);
			if (!lst[lst_index])
				return (lst_index);
			lst_index ++;
		}
		index1 += index2;
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	int		error_index;
	int		word_number;
	char	**word_list;

	word_number = get_word_number(s, c);
	word_list = (char **)malloc((word_number + 1) * sizeof(char *));
	if (!word_list)
		return (NULL);
	error_index = alloc_words(word_list, s, c);
	if (error_index != -1)
	{
		while (error_index >= 0)
			free(word_list[error_index --]);
		free(word_list);
		return (NULL);
	}
	word_list[word_number] = NULL;
	return (word_list);
}

// Get the size of a linked list 
int     stack_size(t_list **stack)
{
	int     count;
	t_list  *node1;

	count = 0;
	node1 = *stack;
	while(node1)
	{
		count++;
		node1 = (node1)->next;
	}
	return (count);
}

// Get last node rank value 
int	get_last_rank(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node->next)
		node = node->next;
	return (node->rank);
}
