/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:30:12 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/12 20:24:49 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_char(char c, char splitter)
{
	if (c == splitter)
		return (1);
	if (c == '\0')
		return (1);
	return (0);
}

static int	count_word(char const *s, char splitter)
{
	int	i;
	int	words;
	int	len;

	words = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len + 1)
	{
		if (i != 0 && is_char(s[i], splitter) == 1
			&& is_char(s[i - 1], splitter) == 0)
			words++;
		i++;
	}
	return (words);
}

static int	occurence_start(char const *s, char c, int start)
{
	while (s[start] != '\0')
	{
		if (s[start] != c)
			return (start);
		start++;
	}
	if (s[start] == '\0')
		return (start - 1);
	return (0);
}

static int	count_diff(char const *s, char c, int start)
{
	int	nbr;
	int	size;

	nbr = 0;
	size = ft_strlen(s);
	while (start < size)
	{
		if (s[start] != c)
			nbr++;
		if (s[start] == c)
			return (nbr);
		start++;
	}
	return (nbr);
}

char	**ft_split(char const *s, char c)
{
	char		**safe;
	int			count_occurence;
	int			search;
	int			start;
	int			nbr_sur;

	start = 0;
	search = 0;
	if (!s)
		return (NULL);
	count_occurence = count_word(s, c);
	safe = malloc(sizeof(char *) * (count_occurence + 1));
	if (!s || !(safe))
		return (NULL);
	while (count_occurence > search)
	{
		nbr_sur = count_diff(s, c, start = occurence_start(s, c, start));
		safe[search] = ft_substr(s, start, nbr_sur);
		if (safe == NULL)
			return (NULL);
		start = start + nbr_sur;
		search++;
	}
	safe[search] = 0;
	return (safe);
}
