/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:17 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:00:11 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*test;

	if ((long long) nmemb < 0 || (long long ) size < 0)
	{
		if (((long long )nmemb < 0 && (long long) size == 0)
			|| ((long long ) size < 0 && (long long) nmemb == 0))
		{
			test = malloc(0);
			return (test);
		}
		return (NULL);
	}
	test = malloc (nmemb * size);
	if (test != NULL)
	{
		ft_bzero(test, nmemb * size);
	}
	return (test);
}
