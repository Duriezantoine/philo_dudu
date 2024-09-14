/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:38:49 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/24 11:39:22 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_(long long n, int count)
{
	int	reste;

	reste = n % 10;
	n = n / 10;
	reste = reste + 48;
	if (n != 0)
		count += putnbr_(n, count);
	write(1, &reste, 1);
	return (count);
}

int	ft_putnbr(int n)
{
	int			count;
	long int	n_long;

	count = 1;
	n_long = (long int ) n;
	if (n_long < 0)
		return (write(1, "-", 1) + putnbr_(-n_long, count));
	return (putnbr_(n_long, count));
}
