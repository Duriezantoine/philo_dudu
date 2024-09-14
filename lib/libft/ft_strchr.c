/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:07:43 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:11:04 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		count;
	int		count_search;
	char	*str;

	count = 0;
	if (c > 256)
		c = c -256;
	count_search = 0;
	str = (char *) s;
	while (str[count] != '\0')
		count++;
	while (count_search <= count)
	{
		if (str[count_search] == c)
			return (&str[count_search]);
		count_search++;
	}
	return (0);
}
