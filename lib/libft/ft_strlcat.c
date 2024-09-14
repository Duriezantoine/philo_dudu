/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:18:52 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/12 20:10:58 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		counter;
	size_t		dest_len;
	size_t		src_len;

	if ((!src || !dst) && size == 0)
		return (0);
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	counter = 0;
	if (dest_len < (size - 1) && size > 0)
	{
		while (src[counter] && dest_len < size - 1)
		{
			dst[dest_len] = src[counter];
			counter++;
			dest_len++;
		}
		dst[dest_len] = 0;
	}
	if (dest_len > size)
		dest_len = size;
	return (dest_len + src_len - counter);
}
