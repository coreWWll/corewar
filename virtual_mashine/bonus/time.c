//
// Created by Denys Burtnjak on 6/30/17.
//

#include "visualisation.h"

void	change_time(t_vm *main_struct, int c)
{
	if (c == '-' && main_struct->time - 1 > 0)
		main_struct->time--;
	else if (c == '+' && main_struct->time + 1 < 1000)
		main_struct->time++;
}

void	time_pause(t_vm *main_struct)
{
	if (main_struct->time > 50)
		usleep((useconds_t) TIME_TWO_MS);
	else
		usleep((useconds_t) TIME_ONE_S / main_struct->time);
}