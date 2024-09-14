/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:22:37 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/27 09:47:29 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	space(char *str, int b)
{
	while (str[b] == ' ' || str[b] == '\f'
		|| str[b] == '\n' || str[b] == '\r'
		|| str[b] == '\t' || str[b] == '\v')
		b++;
	return (b);
}

int	ft_atoi(const char *nptr)
{
	int	b;
	int	i;
	int	j;

	j = 0;
	i = 1;
	b = 0;
	b = space((char *)nptr, b);
	if (nptr[b] == '+' || nptr[b] == '-')
	{
		if (nptr[b] == '-')
			i = i * -1;
		b++;
	}
	if (nptr[b] < '0' && nptr[b] > '9')
		return (0);
	while (nptr[b] >= '0' && nptr[b] <= '9')
	{
		j = j * 10 + (-48 + nptr[b]);
		b++;
	}
	j = j * i;
	return (j);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*test;

	if ((long long)nmemb < 0 || (long long)size < 0)
	{
		if (((long long)nmemb < 0 && (long long)size == 0)
			|| ((long long)size < 0 && (long long)nmemb == 0))
		{
			test = malloc(0);
			return (test);
		}
		return (NULL);
	}
	test = malloc(nmemb * size);
	if (test != NULL)
	{
		ft_bzero(test, nmemb * size);
	}
	return (test);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*safe;
	size_t			count;

	count = 0;
	safe = s;
	while (count < n)
	{
		safe[count] = 0;
		count++;
	}
	return ;
}
