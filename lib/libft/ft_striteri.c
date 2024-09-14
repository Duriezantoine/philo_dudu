/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:51:55 by aduriez           #+#    #+#             */
/*   Updated: 2023/11/13 13:41:19 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	count;

	count = 0;
	if (!s)
		return ;
	while (s[count] != '\0')
	{
		f(count, &s[count]);
		count++;
	}
	return ;
}
