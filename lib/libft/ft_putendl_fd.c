/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:34:00 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:01:04 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return ;
	while (s[count] != '\0')
	{
		write (fd, &s[count], 1);
		count++;
	}
	write (fd, "\n", 1);
}
