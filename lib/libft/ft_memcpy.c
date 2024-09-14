/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:37:42 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/03 19:09:08 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*src_un;
	unsigned char	*dst;

	if (!dest && !src && n)
		return (NULL);
	src_un = (unsigned char *)src;
	dst = (unsigned char *) dest;
	count = 0;
	while (count < n)
	{
		dst[count] = src_un[count];
		count++;
	}
	return (dest);
}
