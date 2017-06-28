//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"
#include <stdio.h>


void change_alive_flag(t_vm *main_struct)
{
	t_player	**player;
	t_car		*car;
	int			i;

	i = 0;
	player = main_struct->players;
	while (player[i])
	{
		car = player[i]->car;
		player[i]->lives_in_current_period = 0;
		while (car)
		{
			if (car->live == 0)
				dell_car_from_list(&(player[i]->car), car);
			car->live = 0;
			car = car->next;
		}
		i++;
	}
}

int check_alive(t_vm *main_struct)
{
	t_player	**player;
	int			i;

	i = 0;
	player = main_struct->players;
	while (player[i])
	{
		if (player[i]->car)
			return (1);
		i++;
	}
    return (0);
}

void	cycles_and_rounds(t_vm *main_struct)
{
	if (main_struct->count_live_functions >= NBR_LIVE ||
		main_struct->max_checks == MAX_CHECKS - 1)
	{
		(main_struct->round)++;
		main_struct->cycle_to_die_for_viz = CYCLE_TO_DIE - CYCLE_DELTA *
														   main_struct->round;
		main_struct->cycle_to_die =	main_struct->cycle_to_die +
				main_struct->cycle_to_die_for_viz;

		main_struct->max_checks = 0;
	}
	else
	{
		main_struct->max_checks++;
		main_struct->cycle_to_die =
				main_struct->cycle_to_die + CYCLE_TO_DIE -
				CYCLE_DELTA * main_struct->round;
	}
	change_alive_flag(main_struct);
	main_struct->nbr_of_lifes = 0;
	main_struct->count_live_functions = 0;
}

void    start_battle(t_vm *main_struct)
{
	while (check_alive(main_struct) && (CYCLE_TO_DIE -
			main_struct->round * CYCLE_DELTA) >= 0)
    {
		if (main_struct->f_dump)
		{
			print_memory((unsigned char *) main_struct->map, MEM_SIZE);
			break ; //need to change. use flag dump in func to EXIT, save 3 lines
		}
		put_caret_on_map(main_struct);
		if (main_struct->f_v == TRUE)
			visualisate(main_struct);
        if (main_struct->cycle == main_struct->cycle_to_die)
			cycles_and_rounds(main_struct);
		move_all_car(main_struct);
		main_struct->processes = count_car(main_struct);
        (main_struct->cycle)++;
		//ft_printf("-----------------------------\n");
		//print_memory((unsigned char *) main_struct->map, MEM_SIZE);
		//ft_printf("cycle = %d, processes = %d\n",main_struct->cycle,
		//		   main_struct->processes);
    }
	if (main_struct->f_v == TRUE)
		while (wgetch(main_struct->vis->arena) != 'q');
}
