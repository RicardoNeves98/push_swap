/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarmo-n <rcarmo-n@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:54:43 by rcarmo-n          #+#    #+#             */
/*   Updated: 2025/12/12 15:43:05 by rcarmo-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

// ft_strlen calculates the length of a given string 
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len ++;
	return (len);
}

// ft_strcmp compares two different strings
int     ft_strcmp(const char *s1, const char *s2)
{
        size_t  i;

        i = 0;
        while (s1[i] && s2[i])
        {
                if (s1[i] != s2[i])
                        break ;
                i ++;
        }
        return (s1[i] - s2[i]);
}


// ft_calloc is function that allocates space for a string and fills it with null terminators 
char	*ft_calloc(size_t n)
{
	size_t	i;
        char    *str;

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

// ft_substr is a function that takes the substring of a given string 
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;
	size_t	str_size;

	count = 0;
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
	while (count < len)
	{
		str[count] = s[start + count];
		count ++;
	}
	return (str);
}

// ft_atoi is a function that turns a string representing a number into an integer 
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
                i ++;
        }
        while (nptr[i] >= '0' && nptr[i] <= '9')
                result = result * 10 + (nptr[i ++] - '0');
        return (sign * result);
}
