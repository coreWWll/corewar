/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_caret_on_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/01 16:40:25 by dburtnja          #+#    #+#             */
/*   Updated: 2017/07/03 18:39:04 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualisation.h"

void	del_old_car(char *color, char *col_time)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (col_time[i] > 0)
			col_time[i]--;
		color[i] = color[i] < 0 ? -color[i] : color[i];
		if (color[i] > COL_NEW_MEM && col_time[i] == 0)
			color[i] -= COL_NEW_MEM;
		i++;
	}
}

void	find_all_palyers_car(t_car *car, char *color)
{
	while (car)
	{
		if (color[car->pos] > 0)
			color[car->pos] = -color[car->pos];
		car = car->next;
	}
}

void	put_caret_on_map(t_vm *main_struct)
{
	int	i;

	i = 0;
	del_old_car(main_struct->color, main_struct->col_time);
	while (main_struct->players_nbr > i)
	{
		find_all_palyers_car(main_struct->players[i]->car, main_struct->color);
		i++;
	}
}
