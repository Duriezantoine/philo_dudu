/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:41:29 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 20:05:22 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		counts1;
	int		counts2;
	char	*safe;

	if (!s1 || !s2)
		return (NULL);
	counts2 = ft_strlen(s2);
	counts1 = ft_strlen(s1);
	safe = malloc(sizeof(char) * (counts1 + counts2 + 1));
	if (safe == NULL)
		return (NULL);
	counts1 = 0;
	counts2 = 0;
	while (s1[counts1] != '\0')
	{
		safe[counts1] = s1[counts1];
		counts1++;
	}
	while (s2[counts2] != '\0')
	{
		safe[counts1++] = s2[counts2++];
	}
	safe[counts1] = '\0';
	return (safe);
}
