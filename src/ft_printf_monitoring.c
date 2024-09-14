/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_monitoring.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:06:13 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/27 09:31:45 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_monitoring(void *arg)
{
	t_base	*base;
	int		i;

	base = (t_base *)arg;
	while (1)
	{
		i = 0;

		while (i < base->number_of_philosophers)
		{
			if (base->dead == true)
			{
				return (NULL);
			}
		}
		i++;
		ft_usleep(10);
	}
	return (NULL);
}

int	ft_printf_status_dead(t_base *base)
{
	if (base->dead == true)
	{
		pthread_mutex_unlock(&base->printf);
		return (1);
	}
	return (0);
}

void	ft_printf_status(t_base *base, t_philo *philo, t_enum status)
{
	pthread_mutex_lock(&base->printf);
	if (ft_printf_status_dead(base) == 1)
		return ;
	if (status == SLEEPING && base->dead == false)
		printf("%lu %d is sleeping\n", (get_current_time() - base->start_time),philo->id);
	else if (status == WAITING && base->dead == false)
		printf("%lu %d has taken a fork\n", (get_current_time()
				- base->start_time), philo->id);
	else if (status == EATING && base->dead == false)
	{
		printf("%lu %d is eating\n", (get_current_time() - base->start_time),
			philo->id );
		philo->last_meal = (get_current_time()- base->start_time);
	}
	else if (status == DEAD)
	{
		printf("%lu %d died\n", (get_current_time()- base->start_time),
			philo->id );
		pthread_mutex_lock(&base->dead_mutex);
		base->dead = true;
		pthread_mutex_unlock(&base->dead_mutex);
		ft_usleep(1);
	}
	else if (status == THINKING)
	{
		printf("%lu %d is thinking\n", (get_current_time()- base->start_time),
			philo->id );	}
	pthread_mutex_unlock(&base->printf);
	return ;
}

void	waiting_philo_pair(t_base *base, t_philo *philo)
{
	pthread_mutex_lock(&base->philo[philo->nbr].fork_left_mutex);
	philo->current_time = get_current_time() - base->start_time;
	ft_printf_status(base, philo, WAITING);
	if (philo->nbr == 0)
	{
		pthread_mutex_lock(&base->philo[base->number_of_philosophers
			- 1].fork_left_mutex);
		philo->current_time = get_current_time() - base->start_time;
		ft_printf_status(base, philo, WAITING);
	}
	else
	{
		if ((philo->current_time - philo->last_meal) > base->time_to_die)
		{
			ft_printf_status(base, philo, DEAD);
			base->dead = true;
			pthread_mutex_unlock(&base->dead_mutex);
			pthread_mutex_unlock(&base->philo[philo->nbr].fork_left_mutex);
			return ;
		}
		pthread_mutex_lock(&base->philo[philo->nbr - 1].fork_left_mutex);
		ft_printf_status(base, philo, WAITING);
	}
}

void	waiting_philo_ood(t_base *base, t_philo *philo)
{
	philo->current_time = get_current_time() - base->start_time;

	if (philo->nbr == 0)
	{
		pthread_mutex_lock(&base->philo[base->number_of_philosophers
			- 1].fork_left_mutex);
		philo->current_time = get_current_time() - base->start_time;
		ft_printf_status(base, philo, WAITING);
		philo->current_time = get_current_time() - base->start_time;
	}
	else
	{
		pthread_mutex_lock(&base->philo[philo->nbr - 1].fork_left_mutex);
		ft_printf_status(base, philo, WAITING);
		philo->current_time = get_current_time() - base->start_time;
	}
	pthread_mutex_lock(&base->philo[philo->nbr].fork_left_mutex);
	ft_printf_status(base,  philo, WAITING);
}
