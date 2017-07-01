/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:39:39 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/01 16:39:41 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

void	change_time(t_vm *main_struct, int c)
{
	if (c == '-' && main_struct->time > 1)
	{
		if (main_struct->time >= 100)
			main_struct->time -= 50;
		else
			main_struct->time--;
	}
	else if (c == '+' && main_struct->time < 10000)
	{
		if (main_struct->time >= 50)
			main_struct->time += 50;
		else
			main_struct->time++;
	}
}

void	time_pause(t_vm *main_struct)
{
	if (main_struct->time > 50)
	{
		main_struct->vis->refresh_time = main_struct->cycle +
				(main_struct->time / 50);
		usleep((useconds_t)TIME_TWO_MS);
	}
	else
		usleep((useconds_t)TIME_ONE_S / main_struct->time);
}
