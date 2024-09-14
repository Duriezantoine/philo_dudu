/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:57:37 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/03 18:37:39 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, long unsigned int n)
{
	unsigned char		*test1;
	unsigned char		*test2;
	long unsigned int	count;

	count = 0;
	test1 = (unsigned char *)s1;
	test2 = (unsigned char *)s2;
	while (count < n)
	{
		if (test1[count] != test2[count])
			return (test1[count] - test2[count]);
		count++;
	}
	return (0);
}
