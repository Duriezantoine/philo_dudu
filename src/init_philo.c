/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:58:43 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/24 15:17:26 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_nbr_philo_utils(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->number_of_philosophers)
	{
		pthread_mutex_init(&base->philo[i].fork_left_mutex, NULL);
		pthread_mutex_init(&base->philo[i].mutex_enum, NULL);
		base->philo[i].state = THINKING;
		base->philo[i].base = base;
		base->philo[i].nbr = i;
		base->philo[i].nbr_meet_philo = 0;
		base->philo[i].id = i+1;
		i++;
	}
}

void	ft_init_phtread_create_philo(t_base *base)
{
	int	i;

	i = 0;
	while (i < base->number_of_philosophers)
	{
		base->philo[i].counter = i;
		if (pthread_create(&base->philo[i].thread_id, NULL, routine,
				&base->philo[i]) != 0)
			printf("ERROR\n");
		i++;
	}
}

void	ft_init_phtread_destroy_philo(t_base *base)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&base->printf);
	pthread_mutex_destroy(&base->dead_mutex);
	while (i < base->number_of_philosophers)
	{
		pthread_mutex_destroy(&base->philo[i].mutex_enum);
		pthread_mutex_destroy(&base->philo[i].fork_left_mutex);
		i++;
	}
}

void	ft_create_montoring_pthreads_join_philo(t_base *base)
{
	int			i;
	pthread_t	monitoring;

	i = 0;
	pthread_create(&monitoring, NULL, ft_monitoring, (void *)base);
	pthread_join(monitoring, NULL);
	while (i < base->number_of_philosophers)
	{
		pthread_join(base->philo[i].thread_id, NULL);
		i++;
	}
}

void	ft_init_threads_nbr_philo(t_base *base)
{
	base->philo = ft_calloc(sizeof(t_philo), base->number_of_philosophers);
	ft_init_nbr_philo_utils(base);
	base->start_time = get_current_time();
	ft_init_phtread_create_philo(base);
	ft_create_montoring_pthreads_join_philo(base);
	ft_init_phtread_destroy_philo(base);
	free(base->philo);
}
