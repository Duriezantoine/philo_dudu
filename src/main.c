/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduriez <aduriez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:35:02 by aduriez           #+#    #+#             */
/*   Updated: 2024/05/24 15:15:13 by aduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/**
 * @brief 
 * @brief 
 *
 * @param envp 
 * @param base BDD
 * @param arg argv from main
 * @param arc argc from main
 */

int	main(int arc, char *arg[])
{
	t_base	base;

	(void)arg;
	if (arc < 5 || arc > 6)
	{
		printf("Numbers arguments invalids\n");
		exit(EXIT_FAILURE);
	}
	if (ft_verif_parsing_arg(arg, arc) == 0)
	{
		printf("Arguments invalid\n");
		exit(EXIT_FAILURE);
	}
	if (ft_init_base(&base, arg, arc) == 1)
		exit(EXIT_FAILURE);
	if (base.nbr_meat == 0)
		exit(EXIT_SUCCESS);
	ft_init_threads_nbr_philo(&base);
	(void)arc;
}
