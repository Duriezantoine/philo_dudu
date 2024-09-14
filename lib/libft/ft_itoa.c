/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:26:30 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/12 20:20:21 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	putnbr_count(long int nbr)
{
	int	count;

	count = 0;
	if (nbr <= 0)
	{
		nbr = nbr * -1;
		count++;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			count;
	char		*safe;

	nbr = (long int)n;
	count = putnbr_count(nbr);
	safe = malloc(sizeof(char) * count +1);
	if (safe == NULL)
		return (NULL);
	safe[count] = '\0';
	if (n < 0)
		nbr = nbr * -1;
	count --;
	while (count >= 0)
	{
		safe[count] = (nbr % 10) + 48;
		nbr = nbr / 10;
		count--;
	}
	if (n < 0)
		safe[0] = '-';
	return (safe);
}
