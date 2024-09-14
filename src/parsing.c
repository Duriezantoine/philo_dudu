/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:56:42 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/24 15:18:06 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_max_min(char *arg[], int arc)
{
	int	i;
	int	check;

	i = 0;
	while (i < arc - 1)
	{
		i++;
		check = ft_atoi(arg[i]);
		if (check > 2147483647 || check <= 0)
		{
			printf("Arguments invalid\n");
			return (1);
		}
	}
	return (0);
}

int	ft_init_base(t_base *base, char *arg[], int arc)
{
	if (check_max_min(arg, arc) == 1)
		return (1);
	base->time_to_eat = ft_atoi(arg[3]);
	base->number_of_philosophers = ft_atoi(arg[1]);
	base->time_to_die = ft_atoi(arg[2]);
	base->time_to_sleep = ft_atoi(arg[4]);
	base->dead = false;
	if (arg[5])
		base->nbr_meat = ft_atoi(arg[5]);
	else
		base->nbr_meat = -1;
	base->counter = 0;
	pthread_mutex_init(&base->printf, NULL);
	pthread_mutex_init(&base->dead_mutex, NULL);
	return (0);
}

void	number_one_philosophers(t_base *base)
{
	printf("0 1 has taken a fork\n");
	ft_usleep(base->time_to_die);
	printf("%d 1 died\n", base->time_to_die);
}

int	ft_verif_parsing(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_verif_parsing_arg(char *arg[], int arc)
{
	int	i;

	(void)arg;
	i = 1;
	while (i < arc)
	{
		if (ft_verif_parsing(arg[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
