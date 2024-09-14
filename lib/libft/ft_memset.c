/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:53:44 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/03 19:14:04 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*temp_str;

	temp_str = (unsigned char *)s;
	counter = 0;
	while (counter < n)
	{
		temp_str[counter] = (unsigned char)c;
		counter++;
	}
	return ((unsigned char *)s);
}
