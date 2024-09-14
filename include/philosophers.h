/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:37:17 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/27 09:44:15 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_base	t_base;

typedef enum s_enum
{
	THINKING,
	EATING,
	WAITING,
	SLEEPING,
	DEAD
}						t_enum;

typedef struct s_philo
{
	pthread_t			thread_id;
	t_base				*base;
	long				current_time;
	int					nbr_meet_philo;
	long				last_meal;
	int					int_fork_left;
	int					int_fork_right;
	pthread_mutex_t		fork_left_mutex;
	int					counter;
	int					nbr;
	t_enum				state;
	pthread_mutex_t		mutex_enum;
	int					id;
}						t_philo;
typedef struct s_base
{
	long				start_time;
	int					nbr_meat;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_philosophers;
	int					counter;
	pthread_mutex_t		printf;
	pthread_mutex_t		dead_mutex;

	bool				dead;
	t_philo				*philo;

}						t_base;

int						main(int arc, char *arg[]);
int						check_max_min(char *arg[], int arc);
void					*ft_monitoring(void *arg);
int						ft_printf_status_dead(t_base *base);
void					ft_printf_status(t_base *base, t_philo *philo,
							t_enum status);
void					waiting_philo_pair(t_base *base, t_philo *philo);
void					waiting_philo_ood(t_base *base, t_philo *philo);
void					ft_init_nbr_philo_utils(t_base *base);
void					ft_init_phtread_create_philo(t_base *base);
void					ft_init_phtread_destroy_philo(t_base *base);
void					ft_create_montoring_pthreads_join_philo(t_base *base);
void					ft_init_threads_nbr_philo(t_base *base);
int						ft_init_base(t_base *base, char *arg[], int arc);
void					number_one_philosophers(t_base *base);
int						ft_verif_parsing(char *arg);
int						ft_verif_parsing_arg(char *arg[], int arc);
unsigned long			get_current_time(void);
int						ft_usleep(size_t milliseconds);
void					fork_release(t_base *base, t_philo *philo);
int						ft_time_to_die(t_base *base, t_philo *philo, int i);
int						philo_status_eating(t_base *base, t_philo *philo);
int						while_whith_philo(t_base *base, t_philo *philo);
void					*routine(void *arg);
int						ft_atoi(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);
void					ft_bzero(void *s, size_t n);

#endif
