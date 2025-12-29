/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:54:43 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/29 18:25:24 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_calloc(size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if ((size_t)-1 / sizeof(char) < n)
		return (NULL);
	else
	{
		str = malloc(n * sizeof(char));
		if (!str)
			return (NULL);
		while (i < n)
			str[i++] = '\0';
	}
	return (str);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	str_size;

	count = -1;
	str_size = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1);
		if (!str)
			return (NULL);
		return (str);
	}
	while (s[start + str_size])
		str_size ++;
	if (str_size < len)
		len = str_size;
	str = ft_calloc(len + 1);
	if (!str)
		return (NULL);
	while (++count < len)
		str[count] = s[start + count];
	return (str);
}

char    *ft_strjoin(char *s1, char *s2)
{
	int             i;
	int             j;
	int             size1;
	int             size2;
	char    *s;

	i = -1;
	j = -1;
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s = ft_calloc(size1 + size2 + 1);
	if (!s)
		return (free(s1), NULL);
	while (++i < size1)
		s[i] = s1[i];
	while (++j < size2)
		s[i + j] = s2[j];
	return (free(s1), s);
}

int     ft_atoi(const char *nptr)
{
	int     i;
	int     sign;
	int     result;

	i = 0;
	sign = 1;
	result = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i ++] - '0');
	return (sign * result);
}
