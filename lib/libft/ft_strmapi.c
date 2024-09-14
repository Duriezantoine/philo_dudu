/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:56:00 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:20:38 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*safe;
	int		size;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	safe = malloc(sizeof(char) * size + 1);
	if (safe == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		safe[i] = f(i, s[i]);
		i++;
	}
	safe[i] = '\0';
	return (safe);
}
