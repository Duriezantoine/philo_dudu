/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:51:52 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:00:43 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	search;
	char	*b;

	search = 0;
	b = (char *)s;
	if (c > 256)
		c = c - 256;
	while (search < n)
	{
		if (b[search] == c)
		{
			return (&b[search]);
		}
		search++;
	}
	return (0);
}
