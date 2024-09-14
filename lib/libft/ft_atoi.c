/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:57:22 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 18:38:42 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	space(char *str, int b)
{
	while (str[b] == ' ' || str[b] == '\f' || str[b] == '\n'
		|| str[b] == '\r' || str [b] == '\t' || str [b] == '\v')
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
	j = j * i ;
	return (j);
}
