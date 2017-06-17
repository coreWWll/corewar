//
// Created by Denys Burtnjak on 6/17/17.
//

#include "visualisation.h"

void	del_old_car(char *color)
{
	int 	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		color[i] = color[i] < 0 ? -color[i] : color[i];
		i++;
	}
}

void	find_all_palyers_car(t_car *car, char *color)
{
	while (car)
	{
		color[car->pos] = -color[car->pos];
		car = car->next;
	}
}

void	put_caret_on_map(t_vm *main_struct)
{
	int 	i;

	i = 0;
	del_old_car(main_struct->color);
	while (main_struct->players_nbr > i)
	{
		find_all_palyers_car(main_struct->players[i]->car, main_struct->color);
		i++;
	}
}