/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:43:05 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:23:01 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;	
	char	*str;

	if (c > 256)
		c = c - 256;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c)
	{
		i--;
		if (i < 0)
			return (NULL);
	}
	return (str + i);
}
