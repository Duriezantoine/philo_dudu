/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:03:23 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:27:14 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set);

static int	is_separator(char c, const char *set)
{
	int	count_set;

	count_set = 0;
	while (set[count_set])
	{
		if (set[count_set] == c)
			return (1);
		count_set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (is_separator(*s1, set) == 1)
	{
		s1++;
		i++;
	}
	len = ft_strlen(s1) - 1;
	while (is_separator(s1[len], set) == 1)
		len--;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	return (ft_substr(s1, 0, (unsigned int) len + 1));
}
