/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:19:05 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/14 13:19:07 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subst;
	size_t			size;
	unsigned int	j;

	j = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (start >= j)
	{
		subst = ft_strdup("");
		return (subst);
	}
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	subst = (char *)malloc(sizeof(char) * (len + 1));
	if (!subst)
		return (NULL);
	ft_strlcpy(subst, s + start, len + 1);
	return (subst);
}
