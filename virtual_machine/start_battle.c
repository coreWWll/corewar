//
// Created by Yevhen Yefimov on 5/27/17.
//

#include "vm.h"


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
				dell_car_from_list(&(player[i]->car), car, main_struct);
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

void	the_winner_is(t_vm *main_struct)
{
	if (main_struct->f_v == FALSE)
		ft_printf("Player: %d -  \"%s\", has won.\n",
				  -main_struct->players[main_struct->winner]->name,
			  main_struct->players[main_struct->winner]->bot_name);
}

void    start_battle(t_vm *main_struct)
{
		while (check_alive(main_struct) && (CYCLE_TO_DIE -
			main_struct->round * CYCLE_DELTA) >= 0)
    {
		if (main_struct->f_dump && main_struct->dump_cycle == main_struct->cycle)
			dump_memory((unsigned char *) main_struct->map, MEM_SIZE);
		move_all_car(main_struct);
		main_struct->processes = count_car(main_struct);
		put_caret_on_map(main_struct);
		if (main_struct->f_v == TRUE && main_struct->vis->go_to_end == FALSE)
			visualisate(main_struct);
        if (main_struct->cycle == main_struct->cycle_to_die)
			cycles_and_rounds(main_struct);
		(main_struct->cycle)++;
    }
	if (main_struct->f_v == TRUE)
	{
		throw_visualization(main_struct, "BATTLE IS OVER");
		while (wgetch(main_struct->vis->arena) != 'q');
		stop_visualisation(main_struct);
	}
	the_winner_is(main_struct);
}
