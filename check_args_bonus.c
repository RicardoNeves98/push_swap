/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:03 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/29 18:25:41 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int     ft_strcmp(const char *s1, const char *s2)
{
	size_t  i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int	check_integer(char *num_str)
{
	int	i;
	int	sign;
	int	str_len;

	i = -1;
	sign = 0;
	str_len = ft_strlen(num_str);
	if (num_str[0] == '+' || num_str[0] == '-')
		i++;
	if (num_str[0] == '+')
		sign = 1;
	else if (num_str[0] == '-')
		sign = -1;
	while (num_str[++i])
		if (num_str[i] < '0' || num_str[i] > '9')
			return (0);
	if (str_len < 10 + (sign % 2))
		return (1);
	else if (str_len > 10 + (sign % 2))
		return (0);
	return (cmp_lim(num_str, sign));
}

int	cmp_lim(char *num_str, int sign)
{
	int	diff;

	diff = 0;
	if (sign == 0)
		diff = ft_strcmp("2147483647", num_str);
	else if (sign == 1)
		diff = ft_strcmp("+2147483647", num_str);
	else if (sign == -1)
		diff = ft_strcmp("-2147483647", num_str);
	if (diff >= 0)
		return (1);
	return (0);
}

int	check_repetition(char **argv, int i)
{
	int	j;
	int	k;

	j = 0;
	while (j < i)
	{
		k = 0;
		while (argv[i][k] && argv[j][k])
		{
			if (argv[i][k] == argv[j][k])
				k++;
			else
				break ;
		}
		if (!argv[i][k] && !argv[j][k])
			return (0);
		j++;
	}
	return (1);
}

int     check_list(char **argv, int argc, int i)
{
	while (argv[++i])
	{
		if (!check_integer(argv[i]) || !check_repetition(argv, i))
		{
			free_stuff(argv, NULL, argc);
			write(2, "Error", 5);
			return (0);
		}
	}
	return (1);
}
