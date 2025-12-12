/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:47:03 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 18:13:58 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (num_str[(sign % 2)] == '0' && str_len > 1 + (sign % 2))
		return (0);
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
