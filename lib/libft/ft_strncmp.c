/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:09:33 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/03 18:25:33 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;
	char	*str_first;
	char	*str_second;

	str_first = (char *)s1;
	str_second = (char *)s2;
	count = 0;
	while (str_first[count] != 0 && str_second[count] != 0 && count < n)
	{
		if (str_first[count] != str_second[count])
		{
			return ((unsigned char)s1[count] - s2[count]);
		}
		count++;
	}
	if (str_first[count] != '\0' && count < n)
		return ((unsigned char)str_first[count]);
	if (str_second[count] != '\0' && count < n)
		return ((unsigned char)0 - str_second[count]);
	return (0);
}
