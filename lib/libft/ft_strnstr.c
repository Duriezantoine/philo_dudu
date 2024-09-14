/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:30:11 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/12 20:07:34 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	count;
	size_t	count2;

	count = 0;
	if (little[count] == '\0' )
		return ((char *)big);
	if (len == 0)
		return (0);
	while (count < len && big[count] != '\0' )
	{
		count2 = 0;
		while (big[count + count2] == little[count2])
		{
			count2++;
			if (little[count2] == '\0' && count2 + count <= len)
				return ((char *)big + count);
		}
		count++;
	}
	return (0);
}
