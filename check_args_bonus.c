/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:03 by rcarmo-n          #+#    #+#             */
/*   Updated: 2026/01/13 11:07:20 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	if (str_len == 1 && sign != 0)
		return (0);
	while (num_str[++i])
		if (num_str[i] < '0' || num_str[i] > '9')
			return (0);
	if (str_len < 10 + pass_zeros(num_str))
		return (1);
	else if (str_len > 10 + pass_zeros(num_str))
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

char	get_sign(char *str)
{
	int		i;
	char	sign;

	i = 0;
	sign = '+';
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		sign = str[i++];
	while (str[i] && str[i] == '0')
		i++;
	if (!str[i])
		return ('0');
	return (sign);
}

int	pass_zeros(char *str)
{
	int	i;

	i = 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && str[i] == '0')
		i++;
	return (i);
}

int	check_repetition(char **argv, int i)
{
	int		j;
	int		k;
	int		w;
	char	sign1;
	char	sign2;

	j = 0;
	sign1 = get_sign(argv[i]);
	while (j < i)
	{
		sign2 = get_sign(argv[j]);
		k = pass_zeros(argv[i]);
		w = pass_zeros(argv[j]);
		while (argv[i][k] && argv[j][w] && (argv[i][k] == argv[j][w]))
		{
			k++;
			w++;
		}
		if (!argv[i][k] && !argv[j][w] && (sign1 == sign2))
			return (0);
		j++;
	}
	return (1);
}
