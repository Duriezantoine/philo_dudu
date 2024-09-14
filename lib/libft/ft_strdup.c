/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:46:07 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/03 15:41:53 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	char	*copy;
	int		count;

	count = 0;
	copy = malloc(sizeof(char) * (ft_strlen((char *)source) + 1));
	if (copy == NULL)
		return (NULL);
	while (source[count] != '\0')
	{
		copy[count] = (char) source[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}
