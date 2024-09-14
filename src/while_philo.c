/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   while_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:03:23 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/24 15:16:39 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	fork_release(t_base *base, t_philo *philo)
{
	pthread_mutex_unlock(&base->philo[philo->nbr].fork_left_mutex);
	if (philo->nbr == 0)
		pthread_mutex_unlock(&base->philo[base->number_of_philosophers
			- 1].fork_left_mutex);
	else
		pthread_mutex_unlock(&base->philo[philo->nbr - 1].fork_left_mutex);
}

int	ft_time_to_die(t_base *base, t_philo *philo, int i)
{
	if (i == 1)
		fork_release(base, philo);
	philo->current_time = get_current_time() - base->start_time;
	if ((philo->current_time - philo->last_meal) > base->time_to_die)
	{
		ft_printf_status(base, philo, DEAD);
		return (1);
	}
	return (0);
}

int	calculates_times_to_eat(t_base *base, t_philo *philo)
{
	philo->current_time = get_current_time() - base->start_time;
	if ((philo->current_time + base->time_to_eat - base-> time_to_sleep
	 - philo->last_meal) > base->time_to_die )
	{
		ft_usleep((base->time_to_die - philo->last_meal) - philo->current_time);
		ft_printf_status(base, philo, DEAD);
		return (1);
	}
	return (0);
}

int	philo_status_eating(t_base *base, t_philo *philo)
{
	if (calculates_times_to_eat(base, philo) == 1)
		return (1);
	if (philo->nbr % 2 == 0)
		waiting_philo_pair(base, philo);
	else
		waiting_philo_ood(base, philo);
	philo->current_time = get_current_time() - base->start_time;
	if ((philo->current_time - philo->last_meal) > base->time_to_die)
		if (ft_time_to_die(base, philo, 1) == 1)
			return (1);
	philo->current_time = get_current_time() - base->start_time;
	ft_printf_status(base, philo, EATING);
	if (ft_time_to_die(base, philo, 0) == 1)
		return (1);
	philo->current_time = get_current_time() - base->start_time;
	ft_usleep(base->time_to_eat);
	philo->nbr_meet_philo++;
	fork_release(base, philo);
	if (philo->nbr_meet_philo == base->nbr_meat && base->nbr_meat > 0)
		return (1);
	return (0);
}

int	while_whith_philo(t_base *base, t_philo *philo)
{
	philo->current_time = get_current_time() - base->start_time;
	if ((philo->current_time - philo->last_meal) > base->time_to_eat * 2)
	{
		if (ft_time_to_die(base, philo, 1) == 1)
			return (1);
	}
	if (philo_status_eating(base, philo) == 1)
		return (1);
	if (ft_time_to_die(base, philo, 0) == 1)
		return (1);
	ft_printf_status(base, philo, SLEEPING);
	if (ft_time_to_die(base, philo, 0) == 1)
		return (1);
	ft_usleep(base->time_to_sleep);
	ft_printf_status(base, philo, THINKING);
	if (ft_time_to_die(base, philo, 0) == 1)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_base	*base;

	philo = (t_philo *)arg;
	base = philo->base;
	philo->last_meal = (base->start_time - get_current_time()) * -1;
	if (base->number_of_philosophers == 1)
	{
		number_one_philosophers(base);
		return (NULL);
	}
	if (philo->nbr % 2 == 0)
		ft_usleep(10);
	while (1)
	{
		if (while_whith_philo(base, philo) == 1)
			break ;
		pthread_mutex_lock(&base->dead_mutex);
		if (base->dead == true)
		{
			pthread_mutex_unlock(&base->dead_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&base->dead_mutex);
	}
	return (NULL);
}
