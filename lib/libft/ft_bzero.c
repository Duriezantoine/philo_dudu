/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:05:26 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/10 19:34:59 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*safe;
	size_t			count;

	count = 0;
	safe = s;
	while (count < n)
	{
		safe[count] = 0;
		count++;
	}
	return ;
}
