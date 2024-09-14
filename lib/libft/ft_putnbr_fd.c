/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:42:41 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:03:37 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_file(int n_long, int fd)
{
	int	reste;

	reste = n_long % 10;
	n_long = n_long / 10;
	reste = reste + 48;
	if (n_long != 0)
		putnbr_file(n_long, fd);
	write(fd, &reste, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	n_long;

	n_long = (long long) n;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n_long < 0)
	{
		n_long = n_long * -1;
		write(fd, "-", 1);
	}
	putnbr_file(n_long, fd);
}
